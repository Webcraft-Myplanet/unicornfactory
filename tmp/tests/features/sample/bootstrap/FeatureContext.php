<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Context\Step;

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
class FeatureContext extends MinkContext

{
	private $returningUser;
	private $adminPassword;
	
    /**
     * Initializes context.
     * Every scenario gets it's own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
      // Initialize your context here
      if(isset($parameters['admin_password'])){
        $this->adminPassword = $parameters['admin_password'];
      }
    }

//
// Place your definition and hook methods here:
//
//    /**
//     * @Given /^I have done something with "([^"]*)"$/
//     */
//    public function iHaveDoneSomethingWith($argument)
//    {
//        doSomethingWith($argument);
//    }
//

    /**
     * Clicks element with specified CSS selector.
     *
     * @When /^(?:|I )click on the element "([^"]*)"$/
     */
    public function clickOnTheElement($locator)
    {
      $session = $this->getSession();
      $element = $session->getPage()->find('css', $locator);
      // Throw an error if the element cannot be found.
      if (null === $element) {
          throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $locator));
      }
      $element->click();
    }
	
	/**
   * @Given /^Returning user exists$/
   */
  public function returningUserExists()
  {
    if($this->returningUser === null){
      $this->returningUser = new stdClass();
      $this->returningUser->username = "test_user_".time();
      $this->returningUser->password = uniqid("test_password_");
      $this->returningUser->email = $this->returningUser->username . "@example.com";

      // Set of steps to create test user
      return array(
        new Step\Given('I log in as admin'),
        new Step\Given('I am on "admin/people/create"'),
        new Step\When('I fill in "edit-name" with "' . $this->returningUser->username . '"'),
        new Step\When('I fill in "edit-mail" with "'.$this->returningUser->email . '"'),
        new Step\When('I fill in "edit-pass-pass1" with "'.$this->returningUser->password . '"'),
        new Step\When('I fill in "edit-pass-pass2" with "'.$this->returningUser->password . '"'),
        new Step\Given('the "status" field should contain "1"'),
        new Step\When('I press "Create new account"'),
        new Step\Then('I should see "Created a new user account"'),
        new Step\Then('go to "/user/logout"')
      );
    }
  }

  /**
   * @Given /^I log in as admin$/
   */
  public function iAmLoggedInAsAdmin()
  {
    if($this->adminPassword === NULL){
      throw new Exception ("Admin password is not configured");
    }
    return array(
      new Step\Given('I am on "/user/login"'),
      new Step\When('I fill in "edit-name" with "admin"'),
      new Step\When('I fill in "edit-pass" with "' . $this->adminPassword . '"'),
      new Step\When('I press "edit-submit"'),
      new Step\Then('I should see "admin"'),
    );
  }

  /**
   * This step is dependant on step "Returning user exists"
   * @Given /^I am logged in as a user$/
   */
  public function iAmLoggedInAsAUser()
  {
    $steps = array();
    // Check if returning user is set.
    if ($this->returningUser === NULL) {
      $steps[] = new Step/Given("Returning user exists");
    }
    $steps += array(
      new Step\Given('I am on "/user/login"'),
      new Step\When('I fill in "edit-name" with "' . $this->returningUser->username . '"'),
      new Step\When('I fill in "edit-pass" with "' . $this->returningUser->password . '"'),
      new Step\When('I press "edit-submit"'),
      new Step\Then('I am on "/dashboard"'),
    );
    return $steps;
  }
}
