
#include "gen/SetSbasUraIndexForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasUraIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasUraIndexForSV::CmdName = "SetSbasUraIndexForSV";
    const char* const SetSbasUraIndexForSV::Documentation = "Set the URA index of a Sbas satellite";

    REGISTER_COMMAND_FACTORY(SetSbasUraIndexForSV);


    SetSbasUraIndexForSV::SetSbasUraIndexForSV()
      : CommandBase(CmdName)
    {}

    SetSbasUraIndexForSV::SetSbasUraIndexForSV(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetSbasUraIndexForSVPtr SetSbasUraIndexForSV::create(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetSbasUraIndexForSV>(svId, urai, dataSetName);
    }

    SetSbasUraIndexForSVPtr SetSbasUraIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasUraIndexForSV>(ptr);
    }

    bool SetSbasUraIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetSbasUraIndexForSV::documentation() const { return Documentation; }


    int SetSbasUraIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetSbasUraIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasUraIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasUraIndexForSV::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetSbasUraIndexForSV::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetSbasUraIndexForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetSbasUraIndexForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
