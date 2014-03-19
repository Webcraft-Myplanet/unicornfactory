Feature: Can sign in to website with Google
  To make it easier for the user to login and register for the site
  As a user of the website
  I can login with Google

@javascript
Scenario: On the login page I can see a button to login with Google
  Given I am on the login page
  Then I should see a Sign In with Google button
