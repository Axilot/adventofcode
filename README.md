# AdventOfCode C Solutions


Hello Adventurer, this year's winter is very cold. But there is hope: Advent of Code 2020 is there. This repo is a work-in-progress to fully cover all challenges. So have fun with it :D


### Current Status

- [x] Day 1
- [x] Day 2
- [x] Day 3
- [x] Day 4
- [x] Day 5
- [ ] Day 6
- [ ] Day 7
- [ ] Day 8
- [ ] Day 9

## How do i compile the solutions?

You simply clone the repository, head into the solution you want to see and run `rake`. After running `rake` you should now have the executables. I included my inputs as a possibility to test the code. And please keep in mind, that this is my first github project, so please be kind with me :D


### Example:
```
git clone https://github.com/Axilot/adventofcode.git
cd adventofcode/Day_01
rake release
./build/day1-1 < day1_input
```

## Dependencies

### Arch

```
sudo pacman -S clang ruby-rake
```
### Debian / Ubuntu
```
sudo apt-get install rake clang
```


## Contribute!

I would really enjoy if you take your time and search for improvements. I really like learning new things and improving my code. So feel free to create issues and pull requests. And if you change code explain why you changed that code and what makes your change "better". And there's just one more thing: Please do not include any third party libraries. Thanks!