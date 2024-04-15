
#include "GetGlonassFrequencyNumberForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassFrequencyNumberForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassFrequencyNumberForEachSV::CmdName = "GetGlonassFrequencyNumberForEachSV";
    const char* const GetGlonassFrequencyNumberForEachSV::Documentation = "Get GLONASS frequency number for all satellites. Return values range from -7 to 13. Value -8 is an invalid value, it indicates that the almanac for the satellite is invalid.";
    const char* const GetGlonassFrequencyNumberForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassFrequencyNumberForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassFrequencyNumberForEachSV);


    GetGlonassFrequencyNumberForEachSV::GetGlonassFrequencyNumberForEachSV()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetGlonassFrequencyNumberForEachSVPtr GetGlonassFrequencyNumberForEachSV::create()
    {
      return std::make_shared<GetGlonassFrequencyNumberForEachSV>();
    }

    GetGlonassFrequencyNumberForEachSVPtr GetGlonassFrequencyNumberForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassFrequencyNumberForEachSV>(ptr);
    }

    bool GetGlonassFrequencyNumberForEachSV::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGlonassFrequencyNumberForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassFrequencyNumberForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetGlonassFrequencyNumberForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
