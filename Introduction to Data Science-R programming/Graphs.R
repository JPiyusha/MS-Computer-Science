#Displaying the bar Graphs

dat <- data.frame(
  student_name = c("John","Bella","Nick","Walt","Farah"),
  total_bill = c(14.89, 17.23, 22.14, 10.57, 17.60)
)
View(dat)

# Load the ggplot2 package
library(ggplot2)

# Very basic bar graph
ggplot(data=dat, aes(x=student_name, y=total_bill)) + geom_bar(stat="identity")

# Map the names to different fill colors
ggplot(data=dat, aes(x=student_name, y=total_bill, fill=student_name)) + geom_bar(stat="identity")

# Add a black outline
ggplot(data=dat, aes(x=student_name, y=total_bill, fill=student_name)) + geom_bar(colour="black", stat="identity")


# No legend, since the information is redundant
ggplot(data=dat, aes(x=student_name, y=total_bill, fill=student_name)) + geom_bar(colour="black", stat="identity") + guides(fill=FALSE)
