jQuery(document).ready(function ($) {

  var data = [
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
    }
]
Chart.defaults.global.responsive = true;

// Boolean - Whether to show labels on the scale
Chart.defaults.global.showTooltips = false;

    // Interpolated JS string - can access value
Chart.defaults.global.tooltipTemplate = "<%if (label){%><%=label%> <%}%>";

// Get context with jQuery - using jQuery's .get() method.
var ctx = $("#myChart").get(0).getContext("2d");
// This will get the first returned node in the jQuery collection.
var myDoughnutChart = new Chart(ctx).Doughnut(data, {
     // Boolean - Whether to animate the chart
    animation: true,
       //Boolean - Whether we should show a stroke on each segment
    segmentShowStroke : true,

    //String - The colour of each segment stroke
    segmentStrokeColor : "#fff",

    //Number - The width of each segment stroke
    segmentStrokeWidth : 2,

    //Number - The percentage of the chart that we cut out of the middle
    percentageInnerCutout : 60, // This is 0 for Pie charts

    //Number - Amount of animation steps
    animationSteps : 80,

    //String - Animation easing effect
    animationEasing : "easeOutExpo",

    //Boolean - Whether we animate the rotation of the Doughnut
    animateRotate : true,

    //Boolean - Whether we animate scaling the Doughnut from the centre
    animateScale : false,

    //String - A legend template
    legendTemplate : "<ul class=\"<%=name.toLowerCase()%>-legend\"><% for (var i=0; i<segments.length; i++){%><li><span style=\"background-color:<%=segments[i].fillColor%>\"></span><%if(segments[i].label){%><%=segments[i].label%><%}%></li><%}%></ul>",

    onAnimationComplete: function() {
            console.log(ctx);
            ctx.fillText(data[0].value + "%", ctx.canvas.attributes.width.value/2 - 20, ctx.canvas.attributes.width.value/2, 200);
            }
    });

});


