To build an run the HereMapsTestApp, you need to add your license data first. 
- Register at https://developer.here.com and get a license data for the HEREMaps iOS SDK Premium Edition.
- Then add your license data in the AppDelegate.cs at this location:<br>
`private static readonly string appId = "YOUR_APP_ID";
private static readonly string appCode = "YOUR_APP_CODE";
private static readonly string appLicenseKey = "YOUR_LICENSE_KEY";`