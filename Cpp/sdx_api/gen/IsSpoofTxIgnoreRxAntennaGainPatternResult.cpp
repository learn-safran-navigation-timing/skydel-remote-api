
#include "IsSpoofTxIgnoreRxAntennaGainPatternResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxIgnoreRxAntennaGainPatternResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxIgnoreRxAntennaGainPatternResult::CmdName = "IsSpoofTxIgnoreRxAntennaGainPatternResult";
    const char* const IsSpoofTxIgnoreRxAntennaGainPatternResult::Documentation = "Result of IsSpoofTxIgnoreRxAntennaGainPattern.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "Ignore bool   If true, the receiver's antenna gain pattern will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const IsSpoofTxIgnoreRxAntennaGainPatternResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxIgnoreRxAntennaGainPatternResult);


    IsSpoofTxIgnoreRxAntennaGainPatternResult::IsSpoofTxIgnoreRxAntennaGainPatternResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSpoofTxIgnoreRxAntennaGainPatternResult::IsSpoofTxIgnoreRxAntennaGainPatternResult(bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    IsSpoofTxIgnoreRxAntennaGainPatternResult::IsSpoofTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIgnore(ignore);
      setId(id);
    }


    IsSpoofTxIgnoreRxAntennaGainPatternResultPtr IsSpoofTxIgnoreRxAntennaGainPatternResult::create(bool ignore, const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPatternResult>(ignore, id);
    }

    IsSpoofTxIgnoreRxAntennaGainPatternResultPtr IsSpoofTxIgnoreRxAntennaGainPatternResult::create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
    {
      return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPatternResult>(relatedCommand, ignore, id);
    }

    IsSpoofTxIgnoreRxAntennaGainPatternResultPtr IsSpoofTxIgnoreRxAntennaGainPatternResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaGainPatternResult>(ptr);
    }

    bool IsSpoofTxIgnoreRxAntennaGainPatternResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxIgnoreRxAntennaGainPatternResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxIgnoreRxAntennaGainPatternResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    bool IsSpoofTxIgnoreRxAntennaGainPatternResult::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void IsSpoofTxIgnoreRxAntennaGainPatternResult::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSpoofTxIgnoreRxAntennaGainPatternResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxIgnoreRxAntennaGainPatternResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
