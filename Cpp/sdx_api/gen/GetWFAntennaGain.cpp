
#include "gen/GetWFAntennaGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaGain::CmdName = "GetWFAntennaGain";
    const char* const GetWFAntennaGain::Documentation = "Get The CRPA LNA gain";

    REGISTER_COMMAND_FACTORY(GetWFAntennaGain);


    GetWFAntennaGain::GetWFAntennaGain()
      : CommandBase(CmdName)
    {

    }

    GetWFAntennaGainPtr GetWFAntennaGain::create()
    {
      return std::make_shared<GetWFAntennaGain>();
    }

    GetWFAntennaGainPtr GetWFAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaGain>(ptr);
    }

    bool GetWFAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetWFAntennaGain::documentation() const { return Documentation; }


    int GetWFAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
