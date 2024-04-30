# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moichou <moichou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:47:56 by moichou           #+#    #+#              #
#    Updated: 2024/01/04 18:30:38 by moichou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


wall "	#Architecture: $(uname -a)
	#CPU physical : $(grep "physical id" /proc/cpuinfo | wc -l)
	#vCPU : $(grep "processor" /proc/cpuinfo | wc -l)
	#Memory Usage: $(free --mega | awk 'NR==2' | awk '{printf "%d/%dMB (%.2f%%)", $3, $2, $3 / $2 * 100}')
	#Disk Usage: $(df -h --total | awk 'NR==10' | awk  '{printf "%d/%dGb (%.f%%)" , $3 * 1024, $2, $3 / $2 * 100}')
	#CPU Load: $(mpstat | awk 'NR==4' | awk '{printf "%.1f%%", 100 - $13}')
	#Last boot: $(who -b | sed "s/system boot//" | awk '{print $1" "$2}')
	#LVM use: $(lsblk | grep lvm | awk '{if ($1) {print "yes";exit;} else {print "no"}}')
	#Connections TCP : $(netstat -an | grep ESTABLISHED | wc -l) ESTABLISHED
	#User log: $(who | awk '{print $1}' | sort -u | wc -l)
	#Network: IP $(hostname -I) $(ip a | grep "link/ether" | awk '{print "("$2")"}')
	#Sudo : $(journalctl _COMM=sudo -q | grep COMMAND | wc -l) cmd"