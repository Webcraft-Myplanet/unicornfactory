CONTENTS OF THIS FILE
---------------------

  * Summary
  * Requirements
  * Installation
  * Google Configuration
  * Configuration
  * Api functions
  * Credits


SUMMARY
-------

This module allows you to authenticate with google,
and use this authentication to carry other api requests.

This module don't have functionality of its own,
but can help you to manage accounts, authenticate with google
(i.e. get access token) and use this authentication to carry api requests.

This module allows you to enter google account details like client id,
client secret key, developer key, select google services to be enabled
and gets the OAuth2 access token from google.

The account manage page also shows a authenticate link if the account is not
authenticated and Revoke link if the account is authenticated.


REQUIREMENTS
------------
1. Libraries API - This modules depends on libraries apis module.
You can download from http://drupal.org/project/libraries
    
2. Google client library - You need to download google api php client library
from http://code.google.com/p/google-api-php-client/downloads/list


INSTALLATION
------------

1. Copy this module directory to your sites/all/modules or
   sites/SITENAME/modules directory.

2. Download the latest release of google php client library and
   extract it in libraries folder of the site, mostly located at
   sites/all/libraries, the path is sites/all/libraries/google-api-php-client.

3. Enable the module and manage accounts at
   admin/config/services/gauth_account.


GOOGLE CONFIGURATION
--------------------
1. Visit https://code.google.com/apis/console
2. Create a new project with appropriate details,
   if you don't have a project created.
3. Under "Services" tab enable the services which you want to use
   i.e. Google Analytics, etc
4. Open "API Access" tab.
5. If you have not created a oauth2.0 client id then create it
   with appropriate details i.e. name, etc
6. Then on next screen select "Application type" web application.
7. Provide your hostname.
8. Edit the Client settings and change the redirect uris to
   "http://example.com/gauth/response_handler" and update.
9. Copy the client id, client secret, api key
   to configuration form of the module.


CONFIGURATION
-------------
1. Configure the api accounts at admin/config/services/gauth_account.

2. You can add new account or update existing accounts.
    Specify unique name by which you can identify the account.
    Add the client id, client secret and api key from you google project page
    i.e. https://code.google.com/apis/console/
    Select services for which this account will be used eg Google Calendar, etc.

3. On save of the form it will ask for access,
   click allow access so that the account gets authenticated.

4. Ready to use this account for api access.


 API FUNCTIONS
 -------------

1. gauth_client_get(account_name)
   This function will return a Google_client object.
   You can use this client object to make api request.
   You can pass account array instead of account_name which has client_id,
   client_secret, developer_key, access_token.

2. gauth_account_load(account_name)
   This functions return a account variable which will have the client_id,
   client_secret key, developer_key, services and importantly the access_token.
   You can use these variables to make a google client object
   and make services call depending on services enabled for the account.

3. gauth_account_delete(account_name);
   This function will allow you to delete an existing managed account
   from drupal site.
   Note: No google account will be deleted.

4. gauth_account_save(account_array)
   This function will allow you to save any existing managed account or
   create a new account in drupal site. It expects an array of account as
   id if you want to update the account
   name Name of the account
   client_id Client Id of the account
   client_secret Clients secret key
   developer_key Api Key of the account
   services Array or comma(,) separated string which has a list of services.
   Names should be as "calendar,drive" refer
   function gauth_google_services_names() in the module for these names.
   Note: Account saved or created using this api will not be authenticated,
         but you will need to call authenticate_api.

5. gauth_account_authenticate(account_name)
   This function allows you to authenticate the account with google and
   get access token from google.

6. gauth_account_token_revoke(account_name)	
   This function allows you to unauthenticate the account with google
   i.e revoke access token from accessing services google.

7. gauth_account_is_authenticated(account_name)
   This function checks if the account is authenticated or not. 


CREDITS
-------

The idea came up from no module providing google oauth2 authentication.

Current Maintainer: Sadashiv Dalvi <dalvisadashiv@gmail.com>
