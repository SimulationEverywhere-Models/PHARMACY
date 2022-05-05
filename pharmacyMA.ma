[top]
components : Dropoff 
components : Labeling

out : out
in : in

Link : in in@Dropoff
Link : out@Dropoff in@Labeling
Link : out@Labeling out


[Dropoff]
components : checkin@Checkin
components : checkfile@Checkfile


in : in
out : out
Link : in in@checkin
Link : out@checkin in@checkfile
Link : out@checkfile out
Link : out@checkfile done@checkin

[checkin]
preparation : 00:00:10:000


[checkfile]
distribution : normal
mean : 4
deviation : 3

[Labeling]
components : filling@Filling
components : consulting@Consulting


in : in
out : out
Link : in in@filling
Link : out@filling in@consulting
Link : out@consulting out
Link : out@consulting done@filling

[filling]
preparation : 00:00:12:000


[consulting]
distribution : normal
mean : 3
deviation : 3


