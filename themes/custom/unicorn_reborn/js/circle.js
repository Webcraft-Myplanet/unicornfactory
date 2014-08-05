jQuery(document).ready(function ($) {

  var totalProgressData = [
    {
      value:  (Drupal.settings.tasks.percent_complete),
      color: "#F05a28",
      highlight: "#FF631B",
      label: "completed"
    },
    {
      value: (Drupal.settings.tasks.percent_incomplete),
      color: "#A9B6C9",
      highlight: "#A9B6C9",
      label: "to be done"
    },
]
  var kicklowData = [
    {
      value:  (Drupal.settings.tasks.kicklow_percent_complete),
      color: "#F05a28",
      highlight: "#FF631B",
      label: "completed"
    },
    {
      value: (Drupal.settings.tasks.kicklow_percent_incomplete),
      color: "#A9B6C9",
      highlight: "#A9B6C9",
      label: "to be done"
    }
]
var bountyData = [
    {
      value:  (Drupal.settings.tasks.bounty_percent_complete),
      color: "#F05a28",
      highlight: "#FF631B",
      label: "completed"
    },
    {
      value: (Drupal.settings.tasks.bounty_percent_incomplete),
      color: "#A9B6C9",
      highlight: "#A9B6C9",
      label: "to be done"
    }
]
Chart.defaults.global.responsive = true;

// Boolean - Whether to show labels on the scale
Chart.defaults.global.showTooltips = false;

    // Interpolated JS string - can access value
Chart.defaults.global.tooltipTemplate = "<%if (label){%><%=label%> <%}%>";

// Get context with jQuery - using jQuery's .get() method.
var ctx = $("#totalProgressChart").get(0).getContext("2d");
var ctx1 = $("#kicklowChart").get(0).getContext("2d");
var ctx2 = $("#bountyChart").get(0).getContext("2d");

// This will get the first returned node in the jQuery collection.
var myDoughnutChart = new Chart(ctx).Doughnut(totalProgressData, {

    //Number - The percentage of the chart that we cut out of the middle
    percentageInnerCutout : 60, // This is 0 for Pie charts

    //Number - Amount of animation steps
    animationSteps : 80,

    //String - Animation easing effect
    animationEasing : "easeOutExpo",

    onAnimationComplete: function() {
            ctx.font = 'bold 23px Arial';
            ctx.textAlign= "center";
            ctx.textBaseline = "middle";
            ctx.fillText(totalProgressData[0].value + "%", ctx.canvas.width/2 , ctx.canvas.width/2);
            }
    });
var myDoughnutChart = new Chart(ctx1).Doughnut(kicklowData, {

    //Number - The percentage of the chart that we cut out of the middle
    percentageInnerCutout : 60, // This is 0 for Pie charts

    //Number - Amount of animation steps
    animationSteps : 80,

    //String - Animation easing effect
    animationEasing : "easeOutExpo",

    onAnimationComplete: function() {
            ctx1.font = 'bold 23px Arial';
            ctx1.textAlign= "center";
            ctx1.textBaseline = "middle";
            ctx1.fillText(kicklowData[0].value + "%", ctx.canvas.width/2 , ctx.canvas.width/2);
            }
    });
var myDoughnutChart = new Chart(ctx2).Doughnut(bountyData, {

    //Number - The percentage of the chart that we cut out of the middle
    percentageInnerCutout : 60, // This is 0 for Pie charts

    //Number - Amount of animation steps
    animationSteps : 80,

    //String - Animation easing effect
    animationEasing : "easeOutExpo",

    onAnimationComplete: function() {
            ctx2.font = 'bold 23px Arial';
            ctx2.textAlign= "center";
            ctx2.textBaseline = "middle";
            ctx2.fillText(bountyData[0].value + "%", ctx.canvas.width/2 , ctx.canvas.width/2);
            }
    });

});


