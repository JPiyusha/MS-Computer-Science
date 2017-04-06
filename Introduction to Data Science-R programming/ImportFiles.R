#this is a program for importing file in R studio

#set path or environment
setwd("C:/R programs")
rawdata <- read.csv("celebrity_deaths.csv")
View(rawdata) #view the data

#Importing the user selected file
rawdata = read.csv(file.choose(), header = TRUE)
View(rawdata)

#importing a text file

rawdata = read.delim(file.choose(), header = FALSE, sep =' ' )
View(rawdata)
