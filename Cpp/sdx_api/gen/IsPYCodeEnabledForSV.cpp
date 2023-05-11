
#include "gen/IsPYCodeEnabledForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForSV::CmdName = "IsPYCodeEnabledForSV";
    const char* const IsPYCodeEnabledForSV::Documentation = "Tells if P(Y)-Code is enabled for the specified satellite.";

    REGISTER_COMMAND_FACTORY(IsPYCodeEnabledForSV);


    IsPYCodeEnabledForSV::IsPYCodeEnabledForSV()
      : CommandBase(CmdName)
    {}

    IsPYCodeEnabledForSV::IsPYCodeEnabledForSV(const std::string& signal, int svId)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
    }

    IsPYCodeEnabledForSVPtr IsPYCodeEnabledForSV::create(const std::string& signal, int svId)
    {
      return std::make_shared<IsPYCodeEnabledForSV>(signal, svId);
    }

    IsPYCodeEnabledForSVPtr IsPYCodeEnabledForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYCodeEnabledForSV>(ptr);
    }

    bool IsPYCodeEnabledForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsPYCodeEnabledForSV::documentation() const { return Documentation; }


    int IsPYCodeEnabledForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsPYCodeEnabledForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYCodeEnabledForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsPYCodeEnabledForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsPYCodeEnabledForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
