> En este caso ya no es código utilizable porque no se tiene el .csv, por lo que se usarán bloques de texto.


##### Multiplicación de una serie por un número:
```py
    air_quality["londong_mg_per_cubic"] = air_quality["londong_mg_per_cubic"] * 1.882
```

##### Dividir una serie por otra serie:
```py
    air_quality["ratio_paris_antwerp"] = (air_quality["station_paris"] / air_quality["station_antwerp"])
```

#### Renombrar columnas:
```py
    air_quality_renamed = air_quality.rename(
        columns={
            "station_antwerp": "BETR801",
            "station_paris": "FR04014",
            "station_london": "London Westminster",
        }
    )
```

#### Poner nombre de columna en minusculas:
```py
    air_quality_renamed = air_quality_renamed.rename(columns=str.lower)
```

#### Buscar parámetros para luego ordenarlos
```py
    no2 = air_quality[air_quality["parameter"] == "no2"]
    no2_subset = no2.sort_index().groupby(["location"]).head(2)
```

#### Realizar un tabla pivote a travez del subset anterior:
```py
    no2_subset.pivot(columns="location", values="value")
```

#### Saca la función de agregado y lo agrupa por la media:
```py
    air_quality.pivot_table(
        values="value", 
        index="location", 
        columns="parameter", 
        aggfunc="mean",
        margins=True,
    )
```

#### Para separar valores: solo con pivot
```py
    no_2 = no2_pivoted.melt(id_vars="date.utc")

    no_2 = no2_pivoted.melt(
        id_vars="date.utc",
        value_vars=["BETR801", "FR04014", "London Westminster"],
        value_name="NO_2",
        var_name="id_location",
    )
```

#### Concatenar DataFrame:
```py
    ait_quality = pd.concat([air_quality_pm25, air_quality_no2], axis=0)
```