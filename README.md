# The Crown: Game Battle

Welcome to **The Crown: Game Battle**! This project is inspired by a combination of childhood card games and royal stories. Compete to claim the title of Crown Prince or Princess by strategically battling through the royal family hierarchy.

## Team VII

- **Dhea Dria Spralia** (231511040)
- **Dhira Ramadini** (231511041)
- **Firgianathyas Siti Fadillah** (231511047)

Politeknik Negeri Bandung  
D3 Teknik Informatika  
2024

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Data Structure](#data-structure)

## Introduction

**The Crown: Game Battle** is a game where players battle against royal family members to become the Crown Prince or Princess. Inspired by card games and royal succession stories, the game involves strategic battles based on various character attributes like Health Points (HP), Intelligence (INT), Power (POW), and Influence (INF).

## Features

1. **Royal Family Hierarchy Creation**:
   - Build the royal family tree, with each member having unique initial points based on their level.
     - Level 0: King - Fixed points.
     - Level 1: Queen and Mistresses - Random points within specified ranges.
     - Level 2: King’s Children - Random points within specified ranges.
     - Level 3: Spouses of King’s Children - Random points within specified ranges.
     - Level 4: King’s Grandchildren - Random points within specified ranges.

2. **Battle Arena**:
   - Engage in battles with family members.
   - Compare attributes to determine winners.
   - Adjust points based on battle outcomes.

3. **Crown Prince/Princess Election**:
   - Candidates are Level 3 members.
   - Calculate average points of INT, POW, and INF to determine the winner.
   - The highest average wins the title.

## Data Structure

We use a tree structure to represent the royal family hierarchy. Here's the structure:

```c
typedef struct t_kerajaan *address; 
typedef struct t_kerajaan { 
    char name;
    int age;
    boolean gender;
    int hp; // Health Points
    int p_pow; // Power Points
    int p_int; // Intelligence Points
    int p_inf; // Influence Points
    address nb; // Next Brother
    address fs; // First Son
    address pr; // Parent
    boolean ptp; // Previously Crown Prince/Princess
} kerajaan; 
typedef address royal_tree;
