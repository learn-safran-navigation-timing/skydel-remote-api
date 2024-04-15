
#include "GetWFAntennaGain.h"

#include "command_factory.h"
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
    const char* const GetWFAntennaGain::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaGain);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaGain);


    GetWFAntennaGain::GetWFAntennaGain()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetWFAntennaGain::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetWFAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
