# Pattern-Mining-of-Amazon-reviewers
Implemented a pattern mining algorithm based on the Apriori Algorithm.

Dataset:

Our transaction database is a set of reviewers from Amazon.com. Specifically, reviewer ids are our items. The transaction is a set
of reviewer ids. Specifically, all reviewer ids which were used to post a review on that product. The format of the transaction
database follows the standard format seen in class. Each line represents a transaction. For a given transaction, the items (reviewer
ids) are separated by a space character.

Implementation:

It is required to mine 𝑘 + frequent itemsets given a minimum support count (min_sup). Essentially, it is required to
implement the Apriori Algorithms. A frequent 𝑘𝑘 itemset refer to an itemset whose size is 𝑘 (i.e., it has 𝑘 elements) and the support of that itemset (no. of times that itemset appears in the transaction database) exceeds min_sup. Frequent 𝑘 + itemsets refers to all frequent itemsets (i.e., itemsets appearing more than min_sup times in the data) which have sizes greater than 𝑘.

Examples and sample Input/Output:

 1. min_sup = 4, 𝑘 = 3                                                                                                                   
    This would yield all itemsets appearing at least 4 times and containing at least 3 elements. Some of results of this query would
    include the following itemsets:                                                                                                     
                                    A37787I8C184FW AWE8HU0AZKASV A3UIATN5XW74NQ (4)                                                     
                                    A3Y9BX5AS769T AWE8HU0AZKASV A3UIATN5XW74NQ (5)                                                       
                                    AZ7I5GAJZA3JO A28R83ADQPMF2X A2GKW94L6HRND7 A2IE7YPWUYZAXS (4)                                       
 
 The first itemset is a frequent 3 itemset having a support count of 4 (i.e., appears 4 times in the data, satisfies the min_sup = 4
 and hence frequent). The second itemset is a frequent 3 itemset with a support of 5 (i.e., it appears 5 times in the transaction
 database). The last itemset is a frequent 4 itemset with a support of 4. Notice that itemsets appearing less than min_sup=4 times 
 should not be retrieved for the above query. There are 53 frequent 3 + itemsets with min_sup=4. The above three are only a few of
 the total 53 frequent 3 + itemsets retrieved for min_sup = 4, 𝑘 = 3.
 
 2. min_sup = 5, 𝑘 = 3                                                                                                         
    This would yield all itemsets appearing at least 5 times (i.e., 5 or more) and containing at least 3 elements. We have exactly 4    such itemsets. The complete result set for the above query is given as follows:                                                         
                                    A9TJYY7P2R280 A2S9IDC1IZH7WN AYFQ8ML2PYZ1D (5)                                                      
                                    A3PXX92YUMGMBG A3UIATN5XW74NQ AWE8HU0AZKASV (5)                                                     
                                    A2J96R1J6MDMEV A3UIATN5XW74NQ AWE8HU0AZKASV (5)                                                     
                                    A3Y9BX5AS769T A3UIATN5XW74NQ AWE8HU0AZKASV (5)
