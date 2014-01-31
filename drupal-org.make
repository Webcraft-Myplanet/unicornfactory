api = 2
core = 7.x

; TEMPLATE

; projects[][subdir] = contrib
; projects[][version] =
; ; This is the issue title: http://drupal.org/node/xxxxxxx#comment-xxxxxxx
; projects[][patch][] =

; MODULES
; Ascending alphabetical order.

projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = 3.0-rc4

projects[auto_nodetitle][subdir] = contrib
projects[auto_nodetitle][version] = 1.0

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.3

projects[devel][subdir] = contrib
projects[devel][version] = 1.3

projects[link][subdir] = contrib
projects[link][version] = 1.2

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.3

projects[features][subdir] = contrib
projects[features][version]	= 2.0

projects[gauth][subdir] = contrib
projects[gauth][version] = 1.3

projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.3

projects[libraries][subdir] = contrib
projects[libraries][version] = 2.1

projects[references][subdir] = contrib
projects[references][version] = 2.1


projects[entity][subdir] = contrib
projects[entity][version] = 1.3

projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.1

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0

projects[views][subdir] = contrib
projects[views][version] = 3.7

; CUSTOM GIT REPO MODULES

projects[custom_config][subdir] = contrib
projects[custom_config][type] = "module"
projects[custom_config][download][type] = "git"
projects[custom_config][download][url] = "git@github.com:sebsebseb123/custom_config.git"
projects[custom_config][download][tag] = "0.1"

; THEMES

projects[bootstrap][subdir] = contrib
projects[bootstrap][version] = 3.0

; LIBRARIES

; libraries[samplelib][download][type] = file
; libraries[samplelib][download][url] = http://example.com/download/samplelib.tar.gz

libraries[google-api-php-client][download][type] = file 
libraries[google-api-php-client][download][url] = "https://google-api-php-client.googlecode.com/files/google-api-php-client-0.6.0.tar.gz"	
