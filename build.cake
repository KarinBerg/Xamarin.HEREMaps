#addin nuget:?package=Cake.SemVer&loaddependencies=true&version=4.0.0

// Script Arguments
var target = Argument("target", "Default");

// Environment
var solutionFile = new FilePath("Xamarin.HEREMaps.sln");
var androidLibrary = GetFiles("./Xamarin.Android.HEREMaps/*.csproj").First();
var iOSLibrary = GetFiles("./Xamarin.iOS.HEREMaps/*.csproj").First();
var artifactsDirectory = new DirectoryPath("artifacts");
var configuration = "Release";
var sourceLicenseFile = new FilePath("./LICENSE");
var targetLicenseFile = new FilePath("./nuspec/LICENSE.txt");

// Versioning. Used for all the packages and assemblies for now. 
// The first three digits corresponds to the HereMaps SDK version whereby the third and the fourth of the hereMaps version is compined to one figure. 
// e.g. HERE SDK version v3.15.2.92 => 2.15.292
// see here for Nuget versioning info: https://docs.microsoft.com/de-de/nuget/concepts/package-versioning
var version = CreateSemVer(3, 15, 292, "alpha", "1");

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

Task("CopyLicense")
	.IsDependentOn("Build")
	.Does(() => { CopyFile(sourceLicenseFile, targetLicenseFile);});

Task("NuGet")
	.IsDependentOn("CopyLicense")
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