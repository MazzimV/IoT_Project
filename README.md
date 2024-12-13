# IoT_Project 2024

Files:

AWS_lambda code is the code used to collect the data in lambda.

S3 Bucket Link: https://eu-west-2.console.aws.amazon.com/s3/buckets/apidataforiotproject?region=eu-west-2&bucketType=general&tab=objects

XGB_Model is the notebook containing the training of the model on historic weather and Oura data.

EC2_Instance_Notebook is where the model is imported and run on the imported data from S3 to generate a predicted bedtime for the most recent data.

activity_sleep_data.csv is the data collected by lambda and stored in S3.


