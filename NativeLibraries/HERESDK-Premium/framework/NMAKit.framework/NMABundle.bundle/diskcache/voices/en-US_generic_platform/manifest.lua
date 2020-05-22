_package_settings = {}
main_attribute_array = {}
package_provider = 02
voice_settings = {}

language = "English (US)"
language_id = "06"
language_loc = "English (US)"
main_attribute_array["LocalizedType"] = "announced street names"
main_attribute_array["language_code"] = "en-US"
main_attribute_array["ngLangCode"] = "eng"
marc_code = "010"
name = "English (US)"



audio_files_path = "resources"
audio_files_version = "0.5.0.201612191429"
config_file = "common.lua"
configurable = "true"
description = language_loc
feature_list = { "metric", "imperial_uk", "imperial_us" }
frequency = 22
id = package_provider..language_id
main_attribute_array["VoiceFeatures"] = "drive;walk;metric;imperialuk;imperialus;naturalguidance;trafficlights;tts"
main_attribute_array["pitch"] = 1.1
main_attribute_array["rate"] = 0.22
network_provider_support_list = "all"
output_type = "tts"
pitch = 1.1
platform_support_list = { '="HERE SDK for Android":>= 1.0' }
rate = 0.22
travel_mode = "0"
tts_engine_type = { "NONE" }
voice_settings["nguidance"] = false
voice_settings["nguidance_junction"] = false
voice_settings["nguidance_stop_sign"] = false
voice_settings["nguidance_trafficlights"] = false
voice_settings["tts_output_format"] = "raw"

localized_quality = "Platform"
pre_packaged = "YES"
