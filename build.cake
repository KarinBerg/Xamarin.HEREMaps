#addin nuget:?package=Cake.SemVer&loaddependencies=true&version=4.0.0

// Script Arguments
var target = Argument("target", "Default");

// Environment
var solutionFile = new FilePath("Xamarin.HEREMaps.sln");
var androidLibrary = GetFiles("./Xamarin.Android.HEREMaps/*.csproj").First();
var iOSLibrary = GetFiles("./Xamarin.iOS.HEREMaps/*.csproj").First();
var artifactsDirectory = new DirectoryPath("artifacts");
var configuration = "Release";

// Versioning. Used for all the packages and assemblies for now.
var version = CreateSemVer(1, 0, 0);

Setup((context) =>
{
    Information ("Starting CAKE script ...");
	Information("Configuration: {0}", configuration);
});

Teardown(context =>
{
    Information ("... CAKE script ended");
});

TaskSetup(setupContext =>
{
    var message = string.Format("Task: {0}", setupContext.Task.Name);
});

TaskTeardown(teardownContext =>
{
    var message = string.Format("Task: {0}", teardownContext.Task.Name);
});

Task("Clean")
	.Does(() =>
	{	
		CleanDirectory(artifactsDirectory);

		MSBuild(solutionFile, settings => settings
				.SetConfiguration(configuration)
				.WithTarget("Clean")
				.SetVerbosity(Verbosity.Minimal));
	});

Task("Restore")
	.Does(() => 
	{
		NuGetRestore(solutionFile);
	});

Task("Build-Android-Library")
	.IsDependentOn("Clean")
	.IsDependentOn("Restore")
	.Does(() =>  
	{	
		MSBuild(androidLibrary, settings => settings
					.SetConfiguration(configuration)
					.WithTarget("Build")
					.SetVerbosity(Verbosity.Minimal));
	});

Task("Build-iOS-Library")
	.IsDependentOn("Clean")
	.IsDependentOn("Restore")
	.Does(() =>  
	{	
		MSBuild(iOSLibrary, settings => settings
					.SetConfiguration(configuration)
					.WithTarget("Build")
					.SetVerbosity(Verbosity.Minimal));
	});

Task("Build")
	.IsDependentOn("Build-Android-Library")
	.IsDependentOn("Build-iOS-Library")
	.Does(() => {});

Task ("NuGet")
	.IsDependentOn("Build")
	.Does (() =>
	{
		Information("Nuget version: {0}", version);
		
  		var nugetVersion = version.ToString();

		NuGetPack ("./nuspec/Xamarin.Android.HEREMaps.nuspec", 
			new NuGetPackSettings 
				{ 
					Version = nugetVersion,
					Verbosity = NuGetVerbosity.Normal,
					OutputDirectory = artifactsDirectory,
					BasePath = "./",
					ArgumentCustomization = args => args.Append("-NoDefaultExcludes")		
				});	

		NuGetPack ("./nuspec/Xamarin.iOS.HEREMaps.nuspec", 
			new NuGetPackSettings 
				{ 
					Version = nugetVersion,
					Verbosity = NuGetVerbosity.Normal,
					OutputDirectory = artifactsDirectory,
					BasePath = "./",
					ArgumentCustomization = args => args.Append("-NoDefaultExcludes")		
				});	
	});

Task("Default")
    .IsDependentOn("NuGet")
    .Does(() =>
{
  Information("Create NuGet packages");
});

RunTarget(target);