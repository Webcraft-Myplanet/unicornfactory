00. The quick overview of what is needed to run the automated tests:
	1. get composer
	2. type "php composer.phar install"
		This will get all the files needed to install behat in bin/behat
	3. get the selenium server driver
	4. get the chromedriver
	5. type "bin/behat"
		This will start running the automated tests.
		You may see the browser flash by, especially you might see a Google login page.
	6. Add more tests to the features directory, see files *.feature
		and modify features/bootstrap/FeatureContext.php
		with suggested php functionality.

The following information is from another project that had more extensive automated tests.
It is useful because it is the reference on where to find the components and how to start
writing behat test senarios.

h1. Behat + Savvis Documentation

* *Installation*
* *Using existing tests*
* *Writing new tests*
* *Workflow*

h2. Installation

# *Get composer*
#* Download composer into your tests directory: 
{code}
curl -sS https://getcomposer.org/installer | php
{code}
# *Install using composer*
#* {code}
php composer.phar install
{code}
Pay attention to the output and install any missing libraries.
# *Get Selenium server.*
#* Download the standalone *Selenium Server (formerly the Selenium RC Server)* jar at http://docs.seleniumhq.org/download/ and save it anywhere you'd like. Here is a direct link: [Selenium Server jar|http://selenium.googlecode.com/files/selenium-server-standalone-2.33.0.jar].
# The latest selenium driver seems to work.
# *Get the chromedriver to use Selinium with Chrome.*
#* Selenium is able to drive Firefox and Safari without any extra drivers. In order to drive Chrome [download the chromedriver|http://code.google.com/p/chromedriver/] for your OS and place it on your path.
# *Create local configuration*
#* Create the local configuration file by:
#*# copy config/default.behat.local.yml to config/local/behat.local.yml
#*# add settings to your behat.local.yml file. You must set file_path and base_url for the existing feature suite to run. Most people will not need to edit or add other settings. Here is an example of how to set browser:
{code}
default:
  extensions:
    Behat\MinkExtension\Extension:
      base_url:  'http://gca.local/'
      javascript_session:  'selenium2'
      browser_name: safari
{code}
# *Verify the installation*
#* Start the Selenium server:
{code}
java -jar <path-to-jarfile> &
{code}
The Selenium server can be shutdown using:
{code}
http://localhost:4444/selenium-server/driver/?cmd=shutDownSeleniumServer
{code}
#* Ensure you're in the tests directory and run
{code}
bin/behat -dl
{code}
If you see a long list of text then you're in business!

h2. Using existing tests

All feature suites are contained in a directory-based structure in the features directory. First, ensure that Selenium server is running on your local. Run 
{code}
bin/behat [--tags [features to test]]
{code}
Where [features to test] is a space-delimited list of tags. For example, "bin/behat" will run the entire GCA feature suite. "bin/behat --profile sample" will run the sample. "bin/behat --tags @product-import" would run only the GCA tests in the "configuration" directory of the GCA tests directory.

You can output tests in a condensed format which only provides additional information about failing tests (rather than all tests) using the *format* flag and the *progress* formatter:
{code}
bin/behat -f progress
{code}

h2. Writing new tests
h3. With no code (using only existing step defintions)

Behat tests are written in a language called [Gherkin|https://github.com/cucumber/cucumber/wiki/Gherkin]. From the Gherkin wiki: 
{quote}
Gherkin is a Business Readable, Domain Specific Language that lets you describe software's behaviour without detailing how that behaviour is implemented.
{quote}

We write tests in a familiar story format using a pre-determined set of phrases, or "steps." Running "bin/behat -dl" will give you a list of the available steps. Some of the steps come with Behat, some come from Mink (the browser extension library for Behat) and some from Drupal.

We assemble these sentences to form a story, or "scenario," about how the application will behave. Each scenario describes a small part of a "feature" of the application we're testing. Please see the [Behat quick intro guide|http://docs.behat.org/quick_intro.html#basic-usage], [feature intro|https://github.com/cucumber/cucumber/wiki/Feature-Introduction] and [given-when-then intro|https://github.com/cucumber/cucumber/wiki/Given-When-Then] for more information. In this guide we will describe where to place your features and scenarios.

h3. Example test

We have been given a story about creating a feature that checks if we can log in. We may write the following feature description as a result of discussion with the stakeholders:

{code}
Feature: Log in
  In order to maintain my information between shopping sessions
  As a user
  I can log into the application
{code}
  
We then decide on scenarios for the feature. One example scenario may be:

{code}
  Scenario: Log in
    Given I am on the homepage
    When I fill in "sahasa" for "username"
    And I fill in "kariya" for "password"
    And I click "Log in"
    Then I should see "My Dashboard"
{code}

Another example scenario:

{code}
  Scenario: Failed log in
    Given I am on the homepage
    When I fill in "sahasa" for "username"
    And I fill in "nottherightpassword" for "password"
    And I click "Log in"
    Then I should see the error message "Login failed. Did you forget your password?"
{code}

If any set up or tear down is necessary (keeping in mind each scenario has it's own FeatureContext) then do so in a beforeScenario or afterScenario.

h3. Where to put your tests

All tests for GCA go in features/gca. If there is a particular epic or functional component (ex: checkout, product configuration) that the feature pertains to, place the feature file in the corresponding feature file. For example, if the feature you are testing is the configuration of resources for a product, you could place the scenarios inside the configurator.feature file. Do not create feature files for individual stories.

h3. Headless vs browser-based tests

Behat performs tests in two modes: headless and browser-based. Headless tests are executed using cURL to fetch pages and a non-interactive browser simulator without any visual output or browser window. Browser-based tests use Selenium or Sahi to drive an actual browser. 

There is a big performance difference between the two modes. If you know the test will not require JavaScript, then write the test as a headless test. Most non-trivial functionality uses Javascript for creating or modifying behavior, so we expect most test cases will need to run in JavaScript mode.

All tests execute in headless mode by default unless you add the "@javascript" tag to the scenario (see the sample suite for an example.)

h3. To speed up writing Behat tests install Sublime Text and download Package Control plugin

To install Packages from Package Control

# Type 'Command+Shift+P'
# Start typing "package" in the command palette and it will show different options.
# Select Install Packages & hit Enter.

Now, Install following Packages to get started.
# Behat
# Sublime-Behat-Snippet
# Cucumber
# Gherkin[Cucumber] Formatter
# Hit 'Command + Shift + P' & type 'Gherkin'. Hit Enter. It will set syntax to "Gherkin".
# Hit 'Command + Shift + P' & type 'feature'. Hit Enter. This will create story format.
# Hit 'Command + Shift + P' & type 'scenario' Or 'Scenario Outline' && Hit Enter. This will create Scenario.
# Hit 'Command + Shift + P' & type 'example' && Hit Enter. This will create example table.

h3. Using custom step definitions

If you would like to write custom step defintions, here are the steps:

# Write the scenario as you would like it to be used
# Run Behat for the profile you've created the step definition in.
# Copy and paste the boilerplate code created by Behat to the FeatureContext.php file that makes sense. If the step definition pertains to Drupal or Angular, put it in the relevant feature context files.
# Implement the step definition!

If you want to have some preconditions in your test ("Given Returning customer exists", for example) you can group the set of actions/steps in one method.

Example:
{code}
  /**
   * @Given /^I am logged in as admin$/
   */
  public function iAmLoggedInAsAdmin()
  {
    return array(
      new Step\Given('I am on "/user/login"'),
      new Step\When('I fill in "edit-name" with "admin"'),
      new Step\When('I fill in "edit-pass" with "' . $this->adminPassword . '"'),
      new Step\When('I press "edit-submit"'),
      new Step\Then('I should see "admin"'),
    );
  }
{code}

Note: iAmLoggedInAsAdmin() uses the adminPassword private member of the FeatureContext class. It sets the value inside the constructor based on the admin_password configuration option. This configuration option should be set in behat.local.yml and can have different values per profile. For example:
{code}
default:
	context:
		  parameters:
			admin_password: "password_on_local"
preprod:
	context:
		  parameters:
			admin_password: "password_on_preprod"
{code}

# Please see the Behat docs for more information.

h2. Workflow

Write your test scenarios before you start working. Write them in Gherkin using existing steps whenever possible. Copy your tests to the correct location in the tests directory and let the reviewers know what feature to run in the comments of your story. You should ensure that all existing tests complete successfully.

It doesn't make sense for some stories to be automated. If that's the case, try to to stick to the general Given-when-then paradigm when writing tests. Let the reviewers know that the test cases are manual and put them in the story in the test session. 

When reviewing others' stories then take note in the story if the tests are manual or automated. If manual, proceed as normal. If automated, then take note of the feature name and run the test using behat.

h2. Creation and deletion of custom accounts

Custom user accounts are created using auto-generated user names and passwords. This is to
avoid the use of custom user names that might already exist. The generated user name and
password is stored as a private variable in the FeatureContext object, for the purpose of re-usual and to avoid
hardcoded login/password strings in other scenario steps. Each scenario receieves it's own FeatureContext object.

The deletion of user accounts will take place in the AfterFeature, within the deleteTestUser
hook function. This will delete any users created.

h2. How to enable trust SSL certificate on chrome

For all browsers:
* Create a self-signed SSL certificate for gca.local and set your vhost to use it.

Chrome:
# In the address bar, click the little lock with the X. This will bring up a small information screen. Click the button that says "Certificate Information".
# Click and drag the image to your desktop. It looks like a little certificate.
# Double-click it. This will bring up the Keychain Access utility. Enter your password to unlock it.
# After it has been added, double-click it. You may have to authenticate again.
# Expand the "Trust" section.
# When using this certificate, set to "Always Trust".

IE:
# Browse to the site whose certificate you want to trust.
# When told "There is a problem with this website's security certificate.", choose "Continue to this website (not recommended)."
# Select Tools->Internet Options.
# Select Security->Trusted sites->Sites.
# Confirm the URL matches, and click "Add" then "Close".
# Close the "Internet Options" dialog box with either "OK" or "Cancel".
# Refresh the current page.
# When told "There is a problem with this website's security certificate.", choose "Continue to this website (not recommended)."
# Click on "Certificate Error" at the right of the address bar and select "View certificates".
# Click on "Install Certificate...", then in the wizard, click "Next".
# On the next page select "Place all certificates in the following store".
# Click "Browse", select "Trusted Root Certification Authorities", and click "OK".
# Back in the wizard, click "Next", then "Finish".
# If you get a "Security Warning" message box, click "Yes".
# Dismiss the message box with "OK".
# Select Tools->Internet Options.
# Select Security->Trusted sites->Sites.
# Select the URL you just added, click "Remove", then "Close".
# Now shut down all running instances of IE, and start up IE again.
# The site's certificate should now be trusted.

Firefox:
# Click the link at the bottom of the error page: "I Understand the Risks" 
# Retrieve the certificate: Add Exception > Get Certificate
# Click "Confirm Security Exception" to enter the site. 

h2. Disable Autocomplete 
IE:
# Click the Tools button Picture of the Tools button, and then click Internet options.
# Click the Content tab.
# Under AutoComplete, click Settings.
# Select or clear the following check boxes:
    Address bar
    Browsing history
    Favorites
    Feeds
    Use Windows Search for better results
    Forms
    User names and passwords on forms
    Ask me before saving passwords
# Click OK, and then click OK again.

Chrome:
# Go to Settings > clear check box Enable Autofill to fill out web forms in a single click

Firefox:
 Preferences > Privacy > History: "Remember search and form history" 

h2. Running regression suite on different browsers

Mink is session oriented. One session in relation with driver. Using behat profiles, we can provide system-wide configuration to accomplish this. Update behat.yml as below to add chrome or safari configurations.

{code}
# behat.yml
default:
  paths:
    features: ../features/gca
    bootstrap: %behat.paths.features%/bootstrap
  extensions:
    Behat\MinkExtension\Extension:
      selenium2:  ~
      goutte: ~
chrome:
  context:
    class:  'FeatureContext'
  extensions:
    Behat\MinkExtension\Extension:
      browser_name: 'chrome'
      goutte: ~
      selenium2:
        browser: 'chrome'
        capabilities: {"browserName":"chrome","browser":"chrome","version":"29"}
safari:
  context:
    class:  'FeatureContext'
  extensions:
    Behat\MinkExtension\Extension:
      browser_name: safari
      goutte: ~
      selenium2:
        browser: 'safari'
        capabilities: {"browserName":"safari","browser":"safari","version":"6"}
iexplore:
  context:
    class:  'FeatureContext'
  extensions:
    Behat\MinkExtension\Extension:
      browser_name: safari
      goutte: ~
      selenium2:
        browser: 'iexplore'
        capabilities: {"browserName":"iexplore","browser":"iexplore","version": "10"}
{code}


h2. Installing chrome driver

# Open another finder window.
# From the Go menu select "Go To Folder".
# Type /usr/bin and press enter.
# Now drag-and-drop the Chromedriver file from your Download folder to this directory. You'll be prompted for your Admin password.
# Restart your computer to allow the changes to take effect.

h2. Running Behat test suites from inside a virtual machine

# Download virtual box (virtualbox.org) and follow this link:
# http://www.modern.ie/en-us/virtualization-tools

# 1. Start selenium as a hub role in the host computer:
#    java -jar selenium-server-standalone-2.35.0.jar -role hub

# 2. Start selenium as a node role in the guest machine:

#  Ex.
#    java -jar selenium.jar -role node -hub http://[IP_ADDRESS]:4444/grid/register -browser browserName=firefox,version=23
#    java -jar selenium.jar -role node -hub http://[IP_ADDRESS]:4444/grid/register -browser browserName=chrome,version=29
#    java -jar selenium.jar -role node -hub http://[IP_ADDRESS]:4444/grid/register -browser browserName=iexplore,version=10

# 3. Go to the virtual box and open up the settings for the running OS.
#    Under network, select bridged Adapter, and select name as en1 (Wifi).

# 4. Go to guest machine and update the hosts file:
#    [ID of host machine]   gca.local
#    Note: It is important that the ID is properly copied over. Otherwise url will not be resolved.

# 5. Launch the test suit from host computer:
#    bin/behat -p=iexplore

#    Note: parameters used for starting up selenium in the guest
#    computer have to match the arguments passed to the test suites.
#    For example, after running:
#      java -jar selenium.jar -role node -hub http://[IP_ADDRESS]:4444/grid/register -browser browserName=chrome,version=29
#    with chrome as the specified browser, you can then only execute tests on the chrome browser by running the following on the host:
#      bin/behat -p=chrome
