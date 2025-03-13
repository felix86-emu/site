---
layout: page
title: Compatibility
permalink: /compat/
---

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Emulator Compatibility List</title>
    <style>
        body { font-family: Arial, sans-serif; }
        .tabs { display: flex; gap: 10px; margin-bottom: 10px; }
        .tab { cursor: pointer; padding: 10px; background: lightgray; border-radius: 5px; }
        .tab.active { background: darkgray; }
        .search { margin-bottom: 10px; }
        .game-list { display: flex; flex-wrap: wrap; gap: 10px; }
        .game { border: 1px solid #ccc; padding: 10px; border-radius: 5px; width: 200px; }
        .status { font-weight: bold; }
        .green { color: green; }
        .yellow { color: orange; }
        .red { color: red; }
    </style>
</head>
<body>
    <h1>Emulator Compatibility List</h1>
    
    <div class="tabs">
        <div class="tab active" onclick="filterCategory('all')">All</div>
        <div class="tab" onclick="filterCategory('working')">Working</div>
        <div class="tab" onclick="filterCategory('partial')">Partially Working</div>
        <div class="tab" onclick="filterCategory('not-working')">Not Working</div>
    </div>
    
    <input class="search" type="text" placeholder="Search games..." onkeyup="searchGames()">
    
    <div class="game-list" id="games">
        <div class="game" data-category="working">
            <img src="game1.jpg" alt="Game 1" width="100%">
            <p>Name: Game 1</p>
            <p class="status green">Working</p>
        </div>
        <div class="game" data-category="partial">
            <img src="game2.jpg" alt="Game 2" width="100%">
            <p>Name: Game 2</p>
            <p class="status yellow">Partially Working</p>
        </div>
        <div class="game" data-category="not-working">
            <img src="game3.jpg" alt="Game 3" width="100%">
            <p>Name: Game 3</p>
            <p class="status red">Not Working</p>
        </div>
    </div>
    
    <script>
        function filterCategory(category) {
            let games = document.querySelectorAll('.game');
            games.forEach(game => {
                game.style.display = (category === 'all' || game.dataset.category === category) ? 'block' : 'none';
            });
            document.querySelectorAll('.tab').forEach(tab => tab.classList.remove('active'));
            event.target.classList.add('active');
        }
        
        function searchGames() {
            let search = document.querySelector('.search').value.toLowerCase();
            document.querySelectorAll('.game').forEach(game => {
                let name = game.querySelector('p').innerText.toLowerCase();
                game.style.display = name.includes(search) ? 'block' : 'none';
            });
        }
    </script>
</body>
</html>
