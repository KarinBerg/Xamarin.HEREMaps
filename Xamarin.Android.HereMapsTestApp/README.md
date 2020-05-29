To build an run the HereMapsTestApp, you need to add your license data first. 
- Register at https://developer.here.com and get a license data for the HEREMaps Android SDK Premium Edition.
- Then add your license data in den AndroidManifest at this location:<br>
`<meta-data android:name="com.here.android.maps.appid" android:value="YOUR_APP_ID"/>
<meta-data android:name="com.here.android.maps.apptoken" android:value="YOUR_APP_TOKEN"/>
<meta-data android:name="com.here.android.maps.license.key" android:value="YOUR_LICENCE_KEY"/>`