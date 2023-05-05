#!/usr/bin/env ruby

# FUNCTION: displays text in a selected color
# ARGUMENT: [txt](string)           the text to display
# ARGUMENT: [colot](string)         text color
# ARGUMENT; [line_break](boolean)   true, for a line break, false otherwise
def print_in_color txt, color, line_break
  color = "\033[0;30m" if color == 'black'
  color = "\033[0;31m" if color == 'red'
  color = "\033[0;32m" if color == 'green'
  color = "\033[0;33m" if color == 'yellow'
  color = "\033[0;34m" if color == 'blue'
  color = "\033[0;35m" if color == 'purple'
  color = "\033[0;36m" if color == 'cyan'
  color = "\033[0;37m" if color == 'white'
  printf("#{color}");
  puts  txt if line_break == true
  print txt if line_break == false
  printf("\033[0m");
end
# END FUNCTION (print_in_color)

WALL = "#"  # change the ascii character to increase readability
ROAD = "."  # change the ascii character to increase readability

# FUNCTION: test fo dante generator
def maze_is_valid buffer, widht, height
  size = 0
  for i in 0..buffer.size
      size += 1
      if buffer[i] == ROAD && buffer[i + 1] == ROAD && buffer[i + widht + 1] == ROAD && buffer[i + widht + 2] == ROAD
          return false
      end
  end
  unless size - 1 == (widht * height + (height)) - 1
      return false
  end
  return true
end
# END FUNCTION (maze_is_valid)

# START of the program:
MAX = 110   # number of iterations (default 101)
x = 9       # the value of the 1st iteration (default 9)
speed = 0.2 # the pause time between each loop (default 0.2)

passed = 0
failed = 0

system "make re"
while x <= MAX
  y = x / 2.5 if x < 51
  y = x / 3.5 if x > 51
  y = 21      if x > 71
  y = y.round 0
  system "clear"
  print_in_color(">>>>> TESTS:", "purple", true)
  print_in_color("width:  ", "purple", false)
  print_in_color("#{x}", "cyan", true)
  print_in_color("height: ", "purple", false)
  print_in_color("#{y}", "cyan", true)
  buffer = `./generator/generator #{x.to_s} #{y.to_s} perfect`
  for i in 0..buffer.size
      buffer[i] = WALL if buffer[i] == "X"
      buffer[i] = ROAD if buffer[i] == "*"
  end
  if maze_is_valid(buffer, x, y)
      print_in_color(buffer, "green", true)
      passed += 1
  else
      print_in_color(buffer, "red", true)
      failed += 1
  end
  print_in_color(">>>>> synthesis: ", "purple", false)
  print_in_color("passed ", "cyan", false)
  print_in_color("#{passed}", "green", false) if passed > 0
  print_in_color("#{passed}", "red", false)   if passed == 0
  print_in_color(" | failed ", "cyan", false)
  print_in_color("#{failed}", "green", true)  if failed == 0
  print_in_color("#{failed}", "red", true)    if failed > 0
  x += 1
  sleep speed
end
temp = `make fclean > test_log_1.txt && rm -rf test_log_1.txt`
# END of the program