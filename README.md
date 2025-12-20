# Sorting scientific articles

The program is designed to sort scientific articles according to certain parameters
# Requirements
- C compiler
- Standard C libraries
- Make (Optional)

# Structure

### Article
Every article contains nine fields:

| Field          | Type                 | Description                                        |
| -------------- | -------------------- | -------------------------------------------------- |
| article_name   | char                 | Article title                                      |
| author_surname | char                 | First author's surname                             |
| initials       | char                 | First author's initials                            |
| journal_name   | char                 | Journal name                                       |
| year           | u_int (unsigned int) | Year of article's publication (1000 < year < 2025) |
| book           | u_int (unsigned int) | Number of book                                     |
| rinc           | bool                 | Included in RINC (YES or NO)                       |
| pages          | u_int (unsigned int) | Number of pages                                    |
| citations      | u_int (unsigned int) | Number of citations                                |

__Article Examlpe__<br>
`Ethics of Machine Learning,Belyatsky,A.Z.,Archives of PMI,1943,5,YES,39,59`
### Container
A doubly linked list is used with support for the following methods:
- Initizalization
- Getting the current size of list
- Getting an any node by index
- Getting data from any node by index
- Getting pointers to the beginning and end
- Getting the next and previous nodes from a pointer
- Adding an element to the beginning, end and an arbitrary position
- Removing an element from the beginning, end and an arbitrary position
- Replacing a pair of elements with each other
- Converting an array to a container
- Convering a container to an array
- Clearing

### Sorting
Two sorts are implemented in the work:
- Bubble sort
- Merge sort
Sorting order of fields (ascending) <br>
`article_name -> author_surname -> initials -> journal_name ->year ->book -> rinc -> citations -> pages`
# Usage 
The program supports 3 main operating modes
1. **Generate** test data `--generate` `-g`
2. **Sort** data `--sort` `-s`
3. **Print** data as a formatted table `--print` `-p`<br>
A combination of operating modes **is prohibited**
## Flags

| Flag                          | Descriptions                                                     |
| ----------------------------- | ---------------------------------------------------------------- |
| -h --help                     | Show help menu                                                   |
| -g N or --generate=N          | Geneerate N random scientific articles (N >= 0)                  |
| -s --sort                     | Sort the list (ascending by default)                             |
| -t A(D) or --type=asc(desc)   | Select the sorting mode (A/asc - ascending, D/desc - descending) |
| -o filename or --out=filename | Output to a file (stdout by default)                             |
| -i filename or --in=filename  | Input from a file (stdin by default)                             |
| -p or --print                 | Output in the form of a fixed-width table                        |
## Building a project

With Make (Makefile) <br>
`make`

## Example
### File `in.csv`
```csv
ARTICLE NAME,AUTHOR_SURNAME,AUTHOR_INITIALS,JOURNAL_NAME,YEAR,BOOK NO,RINC,PAGES,CITATIONS
Security of Gosuslugi (State Services),Orlova,I.I.,Archives of PMI,1931,12,YES,331,41
Ethics of Machine Learning,Shavaliyev,N.A.,Galileo,1982,12,NO,432,15
Ethics of Machine Learning,Novikov,I.M.,Archives of PMI,2012,18,YES,362,67
```
### Command
`lab3.exe --sort -t A -i in.csv`

### Output (Terminal)
```Terminal
ARTICLE NAME,AUTHOR_SURNAME,AUTHOR_INITIALS,JOURNAL_NAME,YEAR,BOOK NO,RINC,PAGES,CITATIONS
Ethics of Machine Learning,Novikov,I.M.,Archives of PMI,2012,18,YES,362,67
Ethics of Machine Learning,Shavaliyev,N.A.,Galileo,1982,12,NO,432,15
Security of Gosuslugi (State Services),Orlova,I.I.,Archives of PMI,1931,12,YES,331,41
```
# License
Academic project. All rights reserved.  
Not intended for redistribution or commercial use.