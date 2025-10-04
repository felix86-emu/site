---
layout: page
title: felix86 Compatibility List
permalink: /compat/
---

<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <style>
    .tabs { display: flex; gap: 10px; margin-bottom: 10px; }
    .tab { cursor: pointer; padding: 10px; background: lightgray; border-radius: 5px; }
    .tab.active { background: darkgray; }
    .search { margin-bottom: 10px; }
    .game-list { display: flex; flex-wrap: wrap; gap: 10px; }
    .game { border: 1px solid #ccc; padding: 10px; border-radius: 5px; width: 200px; text-align: center; transition: transform 0.2s ease-in-out, box-shadow 0.2s ease-in-out; }
    .game:hover { transform: scale(1.05); box-shadow: 0 0 15px rgba(0,0,0,0.3); }
    .game img { width: 100%; height: 150px; object-fit: contain; border-radius: 5px; }
    .status { font-weight: bold; }
    .green { color: green; }
    .yellow { color: orange; }
    .red { color: red; }
    .pagination { margin-top: 20px; display: flex; gap: 5px; flex-wrap: wrap; }
    .pagination button { padding: 5px 10px; border: none; background: lightgray; border-radius: 5px; cursor: pointer; }
    .pagination button.active { background: darkgray; color: white; }
  </style>
</head>
<body>
  <div class="tabs">
    <div class="tab active" onclick="filterCategory('all', this)">All</div>
    <div class="tab" onclick="filterCategory('working', this)">Working</div>
    <div class="tab" onclick="filterCategory('partial', this)">Partially Working</div>
    <div class="tab" onclick="filterCategory('not-working', this)">Not Working</div>
  </div>

  <input class="search" type="text" placeholder="Search games..." onkeyup="applyFilters()">

  <div class="game-list" id="games"></div>
  <div class="pagination" id="pagination"></div>

  <div id="all-games" style="display: none">

<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/894394b6-6b0b-4593-8d0c-b718ada7fc1c" alt="Kerbal Space Program" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/94">Kerbal Space Program</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/fe34538d-7cb4-40a5-bbd5-f6c4fadd8925" alt="Hades" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/93">Hades</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/cf72eab2-96d8-4941-921d-0cfa2aa74a5e" alt="Lethal Company" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/92">Lethal Company</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/4473ae8d-43f9-4a10-8f73-fefbe4705dd3" alt="Touhou 16 - Hidden Star in Four Seasons" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/91">Touhou 16 - Hidden Star in Four Seasons</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/6dbadc73-ae27-43c6-8d06-e5433a855aee" alt="Transport Fever" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/90">Transport Fever</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/4167a8d5-3d8d-40d0-b092-8b45bf1f3bd3" alt="Assassin's Creed" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/89">Assassin's Creed</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/b25798b7-d262-423b-b65f-1a98f88d72a1" alt="DOOM 3" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/88">DOOM 3</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/ddf97435-6fce-4cb4-866f-7f35b1e1e3bf" alt="Hitman: Blood Money" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/87">Hitman: Blood Money</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f1c6d5ef-daba-4b8d-8bd6-84e9dfcd1044" alt="Hollow Knight: Silksong" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/86">Hollow Knight: Silksong</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/56c22612-7253-4f48-b399-3d93ed5c9cf4" alt="Thief Gold" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/85">Thief Gold</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Heroes of Might and Magic 3" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/84">Heroes of Might and Magic 3</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/aaa0b06b-0cd8-4b04-a44c-24276d7671bc" alt="Sleeping Dogs: Definitive Edition" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/83">Sleeping Dogs: Definitive Edition</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/8ea9db53-19d5-485f-8257-1613b3c31d21" alt="Warhammer 40,000: Rites of War" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/82">Warhammer 40,000: Rites of War</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/42ceafc9-ed80-4c7a-ab0d-46715a4d25fa" alt="Super Meat Boy" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/81">Super Meat Boy</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/deea2466-0bc8-434f-a76b-40498fe74eca" alt="RollerCoaster Tycoon: Deluxe" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/80">RollerCoaster Tycoon: Deluxe</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/306649e2-9fea-4c0a-aff3-3846596c92fe" alt="Counter-Strike: Source" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/79">Counter-Strike: Source</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Far Cry 2: Fortune's Edition" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/78">Far Cry 2: Fortune's Edition</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/c132f0c2-fe70-4ddf-88e1-4855c4433c3f" alt="Far Cry" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/77">Far Cry</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/8c52f3f4-dce0-427e-a667-46745a28aaa8" alt="Faster Than Light: Advanced Edition" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/76">Faster Than Light: Advanced Edition</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/a0d7a3bb-f593-4ca5-ae12-f99c8d96768e" alt="Mini Metro" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/75">Mini Metro</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/6b156cfa-016c-4e56-baa5-46cb459f79c3" alt="Fallout 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/74">Fallout 2</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/9051f0d7-eec5-4cbb-bcbf-cd17f24d523a" alt="Enter The Gungeon" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/73">Enter The Gungeon</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/957ad937-aa50-48a5-b204-c6b1c5e76c75" alt="Trackmania Nations Forever" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/72">Trackmania Nations Forever</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/105068ed-3877-4aa2-b2af-1721e721c5b6" alt="SOMA" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/71">SOMA</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/eef8c579-4a1a-488c-b275-c57602862914" alt="SteamWorld Dig 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/70">SteamWorld Dig 2</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/0556cd8f-d519-42d4-a73b-c0b98c313b49" alt="SteamWorld Dig" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/69">SteamWorld Dig</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/b6548c60-df6a-4551-9d6e-33d8cdbb2146" alt="TUNIC" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/68">TUNIC</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/feb3d986-64e8-466b-b7ef-00742372975f" alt="MiSide (Demo)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/67">MiSide (Demo)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/5ddcfab8-bf16-40ef-820d-bf4ee61c2700" alt="Max Payne 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/66">Max Payne 2</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/f5cc7f1a-5f3c-4f09-9b1f-a21c0c5a68b6" alt="Max Payne" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/65">Max Payne</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/0e292c79-41ec-4357-bf0a-156b03476fd4" alt="FEZ" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/64">FEZ</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/8237f31e-5b68-400a-a565-d80e9c352c7e" alt="Baldur's Gate II: Enhanced Edition" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/63">Baldur's Gate II: Enhanced Edition</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/673f7068-4efb-408a-b946-b76a61ddf418" alt="Baldur's Gate: Enhanced Edition" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/62">Baldur's Gate: Enhanced Edition</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/871f7e43-0c4e-4b6d-b7f5-1b344b484be8" alt="Dwarf Fortress" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/61">Dwarf Fortress</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/bb7cc63b-58c7-4f50-95c0-db2e3df58c63" alt="SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/60">SpongeBob SquarePants: Battle for Bikini Bottom - Rehydrated</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/c13821a7-4047-4101-abb8-6a9a18880761" alt="DOOM (2016)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/59">DOOM (2016)</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/92170a81-1576-4b7f-b4ee-c611920a8daa" alt="Europa Universalis IV" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/58">Europa Universalis IV</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/b3005874-bd78-4166-a5f5-b79365deda8a" alt="Factorio Demo" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/57">Factorio Demo</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/b79e31ac-f8c2-4bef-af3a-0ea42e596cd1" alt="Witcher 3" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/56">Witcher 3</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/9d5ec40f-75ac-483c-9892-ceab9f881096" alt="Crysis" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/55">Crysis</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/a9ad7303-3aed-43db-9e50-1a07066172d4" alt="Psychonauts 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/54">Psychonauts 2</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/dd7f4939-06f3-4368-85a1-f12105703660" alt="Witcher 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/53">Witcher 2</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Among Us" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/52">Among Us</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/342d233e-821e-4be3-afa7-b7b0a5dc7993" alt="Deltarune Demo" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/51">Deltarune Demo</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/e449e5b0-5e32-4185-8410-3b3abd388389" alt="Doki Doki Literature Club" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/50">Doki Doki Literature Club</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f83f622e-8e94-41ee-9049-0894db0fd70c" alt="2048" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/49">2048</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/125217ea-166c-4cbc-ad9d-33a642df8d78" alt="Friday Night Funkin' (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/48">Friday Night Funkin' (Windows)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/ba440d24-435f-49f8-88d7-c3cda73f7cec" alt="Sid Meier’s Civilization VI" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/47">Sid Meier’s Civilization VI</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/a7d84731-5960-4a8f-a4e0-7d2331389c25" alt="Hollow Knight" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/46">Hollow Knight</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="A Hat In Time (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/45">A Hat In Time (Windows)</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/c6e1aa3d-ca8e-48f0-a24d-cc5f5d7e779e" alt="Half-Life" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/44">Half-Life</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/78668ac1-f746-460e-ad5e-92c5ff2fdf0e" alt="Counter Strike" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/43">Counter Strike</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/accb8410-b658-43e7-b23e-29b36c5d3760" alt="LIMBO" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/42">LIMBO</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/0e61ccbf-e048-47df-a047-71011527e995" alt="Portal 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/41">Portal 2</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Volley Pals" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/40">Volley Pals</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/0ce543b7-7395-4425-9e1c-ff7e79f1ae76" alt="Bridge Constructor Portal" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/39">Bridge Constructor Portal</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/6e08c31e-8ea9-493d-b9a2-9edc915bf496" alt="140" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/38">140</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/fcd7216f-3fb4-4d90-ae75-13dc7d44b1db" alt="Death Trash (Demo)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/37">Death Trash (Demo)</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/a444dd76-5f6b-469f-a96f-c663fa9d7b94" alt="Bzzzt (Demo)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/36">Bzzzt (Demo)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/dcf8c773-94ac-4a6a-9593-a462fe8cf465" alt="Shogun Showdown: Prologue" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/35">Shogun Showdown: Prologue</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/3f9c73b6-6d6a-4eae-b722-edde2399e2c9" alt="Stardew Valley" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/34">Stardew Valley</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Hotline Miami" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/33">Hotline Miami</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/b8bfd158-6593-496a-90fa-f0a86143ca41" alt="Psychonauts" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/32">Psychonauts</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Amnesia: The Dark Descent" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/31">Amnesia: The Dark Descent</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/e7f19b61-2d7c-49ab-b301-ba6b96df2eb0" alt="Worms W.M.D." width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/30">Worms W.M.D.</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/64a3bdcf-6e3b-446d-87e7-b4cb2d6a4a70" alt="Turok" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/29">Turok</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/54e4f6d1-46e6-413d-815c-b89970ae5654" alt="5D Chess With Multiverse Time Travel" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/28">5D Chess With Multiverse Time Travel</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/d5a56dbc-aa1a-4af6-860c-5c3a6536318b" alt="Undertale" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/27">Undertale</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="https://github.com/user-attachments/assets/859bc9fa-0a37-4083-8e74-cb61d199e89e" alt="Portal" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/26">Portal</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/8d89370b-477f-4d1d-ab41-ab75f4562c1a" alt="Pizza Tower (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/25">Pizza Tower (Windows)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/a087025a-05a9-4a53-b924-185d62311313" alt="World of Goo 2" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/24">World of Goo 2</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f6ce84ae-44e3-4191-9b42-4af3e07666fc" alt="Shovel Knight: Specter of Torment" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/23">Shovel Knight: Specter of Torment</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Terraria" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/22">Terraria</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/2f774381-0efc-4bbe-8374-571cf880e49e" alt="Solitaire (Windows)" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/21">Solitaire (Windows)</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/c6d4418e-20ee-491f-8262-e3c339a81d36" alt="SuperTux" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/20">SuperTux</a></p><p class="status green">Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/c1f49fd0-a12a-4584-b5df-089e9e57a7f6" alt="Absolute Drift" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/19">Absolute Drift</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="partial"><img loading="lazy" src="https://github.com/user-attachments/assets/9344500c-eaf2-494a-bc78-367d4ac078d2" alt="Rogue Legacy" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/18">Rogue Legacy</a></p><p class="status yellow">Partially Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/d5e84a9a-8616-44a1-a29e-e630ee36b314" alt="60 Seconds" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/17">60 Seconds</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/f49cdb0e-c0ab-4637-b3e9-a7cf00a31f2f" alt="Baba Is You" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/16">Baba Is You</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Doom 64" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/15">Doom 64</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/e263df13-15ab-4684-9f60-73c01b2777bb" alt="Outlast" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/14">Outlast</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/76aa91d7-3ac1-4a3a-8bb3-79c301d5e790" alt="Cuphead" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/13">Cuphead</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/73df69d9-1a06-46c6-ba75-503366151830" alt="Untitled Goose Game" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/12">Untitled Goose Game</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/57ce4cc1-00d0-4a61-9b1e-6c0c4da6d965" alt="Hotline Miami 2: Wrong Number" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/11">Hotline Miami 2: Wrong Number</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/35bfab4e-3179-4c4b-9ceb-a0bcdc33aa95" alt="The Binding of Isaac: Rebirth" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/10">The Binding of Isaac: Rebirth</a></p><p class="status green">Working</p></div>
<div class="game" data-category="not-working"><img loading="lazy" src="{{ site.baseurl }}/images/felixNoThoughts.png" alt="Papers, Please" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/9">Papers, Please</a></p><p class="status red">Not Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/31a3549f-bc95-466d-9835-8c23edfc59f4" alt="Don't Starve" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/8">Don't Starve</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/b64a3add-9848-45b5-99c0-70c5b00d80a6" alt="Dimension Tripper Neptune: TOP NEP" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/7">Dimension Tripper Neptune: TOP NEP</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/ce5c5813-977f-4f43-a371-add71944800d" alt="World of Goo" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/6">World of Goo</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/288b24a4-fe91-4309-8bc2-fd3c8a0d0a53" alt="Celeste" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/5">Celeste</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/28f85114-5a77-4afe-99bf-64bdf2aa0d6d" alt="openarena" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/4">openarena</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/13bbd99a-3b53-46bf-84e1-c854e664f315" alt="SuperTuxKart" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/3">SuperTuxKart</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/ae9186c3-8777-40ae-b26b-3a0461ca0b47" alt="VVVVVV" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/2">VVVVVV</a></p><p class="status green">Working</p></div>
<div class="game" data-category="working"><img loading="lazy" src="https://github.com/user-attachments/assets/47ff1b5f-4d15-45dd-8dfb-bfa512b881f7" alt="Balatro" width="100%"><p><a href="https://github.com/felix86-emu/compatibility-list/issues/1">Balatro</a></p><p class="status green">Working</p></div>


  </div>

  <script>
    const allGames = Array.from(document.querySelectorAll('#all-games .game'));
    const gameContainer = document.getElementById('games');
    const pagination = document.getElementById('pagination');
    let filteredGames = allGames;
    let currentPage = 1;
    const gamesPerPage = 9;
    let currentCategory = 'all';

    function filterCategory(category, tabElement) {
      currentCategory = category;
      currentPage = 1;
      document.querySelectorAll('.tab').forEach(tab => tab.classList.remove('active'));
      tabElement.classList.add('active');
      applyFilters();
    }

    function applyFilters() {
      const search = document.querySelector('.search').value.toLowerCase();

      filteredGames = allGames.filter(game => {
        const matchesCategory = currentCategory === 'all' || game.dataset.category === currentCategory;
        const matchesSearch = game.querySelector('p').innerText.toLowerCase().includes(search);
        return matchesCategory && matchesSearch;
      });

      currentPage = 1;

      renderGames();
      renderPagination();
    }

    function renderGames() {
      gameContainer.innerHTML = '';
      const start = (currentPage - 1) * gamesPerPage;
      const end = start + gamesPerPage;
      const gamesToShow = filteredGames.slice(start, end);
      gamesToShow.forEach(game => gameContainer.appendChild(game.cloneNode(true)));
    }

    function renderPagination() {
      pagination.innerHTML = '';
      const totalPages = Math.ceil(filteredGames.length / gamesPerPage);
      for (let i = 1; i <= totalPages; i++) {
        const btn = document.createElement('button');
        btn.textContent = i;
        btn.classList.toggle('active', i === currentPage);
        btn.onclick = () => {
          currentPage = i;
          renderGames();
          renderPagination();
        };
        pagination.appendChild(btn);
      }
    }

    window.onload = () => {
      applyFilters();
    };
  </script>
</body>
</html>

Generated from [https://github.com/felix86-emu/compatibility-list](https://github.com/felix86-emu/compatibility-list)
