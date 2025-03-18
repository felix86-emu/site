---
layout: page
title: Compatibility
permalink: /compat/
---

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>felix86 Compatibility List</title>
    <style>
        body { font-family: Arial, sans-serif; }
        .tabs { display: flex; gap: 10px; margin-bottom: 10px; }
        .tab { cursor: pointer; padding: 10px; background: lightgray; border-radius: 5px; }
        .tab.active { background: darkgray; }
        .search { margin-bottom: 10px; }
        .game-list { display: flex; flex-wrap: wrap; gap: 10px; }
        .game { border: 1px solid #ccc; padding: 10px; border-radius: 5px; width: 200px; text-align: center; }
        .game img { width: 100%; height: 150px; object-fit: cover; border-radius: 5px; }
        .status { font-weight: bold; }
        .green { color: green; }
        .yellow { color: orange; }
        .red { color: red; }
    </style>
</head>
<body>
    <h1>felix86 Compatibility List</h1>
    
    <div class="tabs">
        <div class="tab active" onclick="filterCategory('all')">All</div>
        <div class="tab" onclick="filterCategory('working')">Working</div>
        <div class="tab" onclick="filterCategory('partial')">Partially Working</div>
        <div class="tab" onclick="filterCategory('not-working')">Not Working</div>
    </div>
    
    <input class="search" type="text" placeholder="Search games..." onkeyup="searchGames()">
    
    <div class="game-list" id="games">
        
<div class="game" data-category="not-working"><img src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Doom 64" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/15">Doom 64</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img src="https://github.com/user-attachments/assets/e67f8e2b-3343-41d0-9d29-bd18017d6de4" alt="Outlast" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/14">Outlast</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Cuphead" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/13">Cuphead</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Untitled Goose Game" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/12">Untitled Goose Game</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Hotline Miami 2: Wrong Number" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/11">Hotline Miami 2: Wrong Number</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/445718f0-b535-4661-8fb1-a1323d739911" alt="The Binding of Isaac: Rebirth" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/10">The Binding of Isaac: Rebirth</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="not-working"><img src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Papers, Please" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/9">Papers, Please</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/b8fe2570-8026-4372-993d-539da67d7fb9" alt="Don't Starve" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/8">Don't Starve</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/fd3ff722-6e68-4db5-b7bb-fbd35b53e6c4" alt="Dimension Tripper Neptune: TOP NEP" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/7">Dimension Tripper Neptune: TOP NEP</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img src="https://github.com/user-attachments/assets/ce5c5813-977f-4f43-a371-add71944800d" alt="World of Goo" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/6">World of Goo</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/df3b64cf-b534-4253-b925-b020851668e6" alt="Celeste" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/5">Celeste</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/afaeb352-40e3-4401-b54f-ef00c73783e6" alt="openarena" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/4">openarena</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img src="https://github.com/user-attachments/assets/13bbd99a-3b53-46bf-84e1-c854e664f315" alt="SuperTuxKart" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/3">SuperTuxKart</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img src="https://github.com/user-attachments/assets/ae9186c3-8777-40ae-b26b-3a0461ca0b47" alt="VVVVVV" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/2">VVVVVV</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img src="https://github.com/user-attachments/assets/47ff1b5f-4d15-45dd-8dfb-bfa512b881f7" alt="Balatro" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/1">Balatro</a></p><p class="status green">Working</p></div>

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
