# IoT Project 2024

Files:

AWS_lambda code is the code used to collect the data in lambda.

activity_sleep_data.csv is the data collected by lambda and stored in S3.

XGB_Model is the notebook containing the training of the model on historic weather and Oura data.

EC2_Instance_Notebook is where the model is imported and run on the imported data from S3 to generate a predicted bedtime for the most recent data.



DataPullS3 is the code for the data pull from S3
Led_light.ino is the code for the dimmming of the LED light over the course of an hour
