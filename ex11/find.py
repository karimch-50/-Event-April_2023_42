import requests

name = input("Enter the name of a Pokemon: ").lower()
url = f"https://pokeapi.co/api/v2/pokemon/{name}"

res = requests.get(url)
if res.status_code == 200:
	data = res.json()
	abilities = data['abilities']
	print(f"Name: {name.capitalize()}")
	print("Abilities:")
	for ab in abilities:
		print(f"- {ab['ability']['name'].capitalize()}")
else:
	print("not valid")