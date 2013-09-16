#!/usr/bin/perl

foreach my $file (glob "*") {
    my $source = $file;
    open IN, $source
        or die "Can't open '$source' for input: $!";

    my $dest = "$file.new";
    die "Won't overwrite existing file"
    if -e $dest;
    open OUT, ">$dest"
        or die "Can't open '$dest' for output: $!";

    my $pattern = $ARGV[0];
    my $replace = $ARGV[1];

    while (<IN>) {
        s/$pattern/$replace/g;
        print OUT $_;
    }

    unlink $source;
    rename $dest, $source;
}
