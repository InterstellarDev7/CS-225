
            #!/bin/bash
            clear  # Clear the terminal screen at the start
            cd "/Users/macbook/Library/CloudStorage/OneDrive-Embry-RiddleAeronauticalUniversity/Academic Years/2024-2025/Spring 2025/CS 225/VS Code/CS-225/Projects"
            if [ -f game ]; then
                rm game  # Remove the old binary if it exists
            fi
            g++ -o game game.cpp
            if [ $? -eq 0 ]; then
                ./game
            else
                echo "Compilation failed."
            fi
            echo ""  # Add a newline for better separation
            rm "/Users/macbook/Library/CloudStorage/OneDrive-Embry-RiddleAeronauticalUniversity/Academic Years/2024-2025/Spring 2025/CS 225/VS Code/CS-225/Projects/.game_run.sh"
        