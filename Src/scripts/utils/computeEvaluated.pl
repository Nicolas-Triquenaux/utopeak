#!/usr/bin/perl

#
# UtoPeak - Automatic Estimation of DVFS Potential
# Copyright (C) 2013 Universite de Versailles
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#


use strict;

my $ARGC = $#ARGV+1;
if( $ARGC != 1)
{
        print "./computeEvaluated.pl data_input\n";
        die;
}

my $data = $ARGV[0];

open FILE, $data or die $!;


my $min = 1000000000000;

while(my $line = <FILE>)
{
   chomp $line;
   if ($line < $min)
   {
      $min = $line;
   }
}
close(FILE);
print $min;