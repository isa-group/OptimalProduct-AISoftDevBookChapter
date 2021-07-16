library(readr)
library(xtable)
populationObj <- read_delim("C:/workspace/papers/AIBookChapter/OptimalProduct/NSGA-II(SIP)/Debug/populationObj", 
                            "\t", escape_double = FALSE, trim_ws = TRUE)
View(populationObj)

names(populationObj) <- c("ConstraintViolations","MissingFeatures","LinesOfCode","CyclomaticComplexity","Test assertions","Installations","Developers","Changes")
summary(populationObj)
xtable(as.table(summary(populationObj)), type = "latex")
