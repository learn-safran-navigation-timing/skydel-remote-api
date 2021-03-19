using System;
using Newtonsoft.Json;

namespace Sdx
{
  internal class CommandBaseConverter : JsonConverter
  {
    public override bool CanConvert(Type objectType)
    {
      return typeof(CommandBase).IsAssignableFrom(objectType);
    }

    public override object ReadJson(JsonReader reader, Type objectType, object existingValue, JsonSerializer serializer)
    {
      throw new NotImplementedException();
    }

    public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
    {
      ((CommandBase)value).Json.WriteTo(writer);
    }
  }
}