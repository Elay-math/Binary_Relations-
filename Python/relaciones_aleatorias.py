import random
import string

def lista_aleatoria(num_elementos):
    if num_elementos <= 26:
        elementos = list(string.ascii_lowercase[:num_elementos])
    else:
        letras = list(string.ascii_lowercase)
        numeros_faltantes = num_elementos - 26
        numeros = [str(x) for x in random.sample(range(1, 10000), numeros_faltantes)]
        elementos = letras + numeros

    cantidad_inicial = random.randint(1, num_elementos * 2)
    relaciones = {(random.choice(elementos), random.choice(elementos)) for _ in range(cantidad_inicial)}

    if random.choice([True, False]):
        for e in elementos:
            relaciones.add((e, e))
    elif random.choice([True, False]):
        relaciones = {(a, b) for a, b in relaciones if a != b}

    if random.choice([True, False]):
        relaciones.update({(b, a) for a, b in relaciones})

    if random.choice([True, False]):
        while True:
            nuevas = {(a, c) for a, b in relaciones for b2, c in relaciones if b == b2}
            if nuevas.issubset(relaciones):
                break
            relaciones.update(nuevas)

    relaciones_formateadas = [f"{a}R{b}" for a, b in relaciones]
    random.shuffle(relaciones_formateadas)
    
    return elementos, relaciones_formateadas

