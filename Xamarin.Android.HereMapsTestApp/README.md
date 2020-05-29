To build an run the HereMapsTestApp, you need to add your license data first. 
- Register at https://developer.here.com and get a license data for the HEREMaps Android SDK Premium Edition.
- Change the package name of the app to the one you used for the HereMaps license. (Otherwise the license will not be accepted)
- Then add your license data in den AndroidManifest at this location:<br>
`<meta-data android:name="com.here.android.maps.appid" android:value="YOUR_APP_ID"/>`<br>
`<meta-data android:name="com.here.android.maps.apptoken" android:value="YOUR_APP_TOKEN"/>`<br>
`<meta-data android:name="com.here.android.maps.license.key" android:value="YOUR_LICENCE_KEY"/>`<br>