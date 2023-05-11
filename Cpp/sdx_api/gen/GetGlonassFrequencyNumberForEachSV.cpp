
#include "gen/GetGlonassFrequencyNumberForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetGlonassFrequencyNumberForEachSV);


    GetGlonassFrequencyNumberForEachSV::GetGlonassFrequencyNumberForEachSV()
      : CommandBase(CmdName)
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


    int GetGlonassFrequencyNumberForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
