using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sdx
{
  class DateTimeConverter : JsonConverter
  {
    public override bool CanConvert(Type objectType)
    {
      return objectType == typeof(DateTime);
    }

    public override object ReadJson(JsonReader reader, Type objectType, object existingValue, JsonSerializer serializer)
    {
      Dictionary<string, int?> values = new Dictionary<string, int?>
      {
        { "Year",  null },
        { "Month",  null },
        { "Day",  null },
        { "Hour",  null },
        { "Minute",  null },
        { "Second",  null }
      };
      while (reader.Read() && reader.TokenType == JsonToken.PropertyName)
      {
        if ((string)reader.Value == "Spec")
        {
          if (reader.ReadAsString() != "UTC")
            throw new Exception("Unexpected value.");
        }
        else
        {
          if (!values.ContainsKey((string)reader.Value))
            throw new Exception("Unexpected value.");
          values[(string)reader.Value] = reader.ReadAsInt32();
        }
      }
      return new DateTime(values["Year"].GetValueOrDefault(0), values["Month"].GetValueOrDefault(0), values["Day"].GetValueOrDefault(0), values["Hour"].GetValueOrDefault(0), values["Minute"].GetValueOrDefault(0), values["Second"].GetValueOrDefault(0));
    }

    public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
    {
      DateTime dt = (DateTime)value;

      JObject o = new JObject();
      o["Year"] = dt.Year;
      o["Month"] = dt.Month;
      o["Day"] = dt.Day;
      o["Hour"] = dt.Hour;
      o["Minute"] = dt.Minute;
      o["Second"] = dt.Second;
      o["Spec"] = "UTC";

      o.WriteTo(writer);
    }
  }
}