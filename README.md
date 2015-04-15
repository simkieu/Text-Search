# Text-Search

Develop an algorithm will take as input a se quence of k > 1 textfiles T1, T2, ..., Tk, of
respective lengths n 1, n 2, ...n k, e.g., books or program listings, and it will adapt them in
form of a suitable structure capable of supporting subsequent queries of the kind specified
below.

A user will specify a query string, call it w, and one of the option modes ’search’ or
’stat’, each followed by suboption ’1’ or ’2’.

If the ’search’ mode is specified, the system must report the following. Under suboption
’1’: ’yes’ if w appears in the textfiles, ’no’ otherwise. Under suboption ’2’: if w appears
in the textfiles, the system reports the starting positions of all occurrences of w, it reports
’not found’ otherwise.

If the ’stat’ mode is specified, the system must report the following. Under suboption
’1’: the number of occurrences of w in the textfiles. Under suboption ’2’: the number and
name of the distinct textfiles that contain each at least one occurrence of w.
