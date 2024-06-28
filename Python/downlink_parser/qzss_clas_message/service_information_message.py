def serviceInformationMessage(msg, multiplicity):
    dataSize = int(msg[f"Data Size {multiplicity}"]["decimal"])
    header = {
        "Message Number": int(msg[f"Message Number {multiplicity}"]["decimal"]),
        "Message Sub Type ID": int(
            msg[f"Message Sub Type ID {multiplicity}"]["decimal"]
        ),
        "Multiple Message Indicator": int(
            msg[f"Multiple Message Indicator {multiplicity}"]["decimal"]
        ),
        "Information Message Counter": int(
            msg[f"Information Message Counter {multiplicity}"]["decimal"]
        ),
        "Data Size": dataSize,
    }

    service_per_sys = []
    for aux in range(dataSize + 1):
        service_per_sys.append(
            {
                "Auxiliary Frame Data": msg[
                    "Auxiliary Frame Data nb{0} {1}".format(aux, multiplicity)
                ]["binary"]
            }
        )

    return {
        f"Service Information Message {multiplicity}": {
            **header,
            "Service Information Datas": service_per_sys,
        }
    }


def handleServiceInformationMessage(gen, nsys, satCounts, multiplicity):
    gen.addParametertoDict(f"Message Number {multiplicity}", 12)
    gen.addParametertoDict(f"Message Sub Type ID {multiplicity}", 4)
    gen.addParametertoDict(f"Multiple Message Indicator {multiplicity}", 1)
    gen.addParametertoDict(f"Information Message Counter {multiplicity}", 3)
    dataSize = gen.getParameterValue(2)
    gen.addParametertoDict(f"Data Size {multiplicity}", 2)
    for auxData in range(dataSize + 1):
        gen.addParametertoDict(
            "Auxiliary Frame Data nb{0} {1}".format(auxData, multiplicity), 40
        )
