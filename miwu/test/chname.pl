#!/usr/bin/perl

$old = $ARGV[0];
$new = $ARGV[1];

foreach my $file (glob "$old*") {
    $new_file = $file;
    $new_file =~ s/$old/$new/;
    if (-e $new_file) {
        warn "$new_file exists!\n";
    } else {
        rename $file, $new_file
            or warn "rename failed: $!\n";
    }
}
