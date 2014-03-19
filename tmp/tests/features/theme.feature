Feature: Theme
  In order to identify with the brand
  As a website user
  I need to be to use the themed site
  
  Scenario: Custom theme is enabled
    Given I log in as admin
    When I go to "admin/appearance"
    Then I should see "Unicorn"

	Scenario: Homepage of Unicorn Factory
	  Given I go to the homepage
	  Then I should see "Unicorn Factory"

	Scenario: On any page of Unicorn Factory
	  Given I go to the homepage
	  Then I should see "Projects"
	  And I should see "Teams"
		And I should see "People"
	
	
	