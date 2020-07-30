# BreadMonitor2
## BreadMonitor2 is a "Hello world" C++ RaspberryPI applictaion for monitoring CO2 production in bread making.
## Usage
The CO2 sensor attached to the Raspberry PI is placed in the covered bread container and the application started. The applicaion is started by remotely sshing into the Raspberry PI and running the application *BreadMonitor2.out*. Periodically the application will sample CO2 and HTTP the results to the monitoring server

## Options
-nBatchName - Name of the bread batch. Default is "Batch"

-iURL - URL of the monitoring web application. Default is "http://192.168.50.5:3000/"

-dDuration - Length of time to monitor in hours. Default is 12 hours


Example: `./BreadMonitor2.out -nWhiskey`

## Notes
See repositary BreadMonitor for the Web server/client applications use to collect and display the results of the Raspberry PI CO2 application.
