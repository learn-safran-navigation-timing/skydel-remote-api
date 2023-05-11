
#include "gen/SetGalileoSisaE1E5bIndexForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSisaE1E5bIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSisaE1E5bIndexForSV::CmdName = "SetGalileoSisaE1E5bIndexForSV";
    const char* const SetGalileoSisaE1E5bIndexForSV::Documentation = "Set the SISA(E1,E5b) index of a Galileo satellite";

    REGISTER_COMMAND_FACTORY(SetGalileoSisaE1E5bIndexForSV);


    SetGalileoSisaE1E5bIndexForSV::SetGalileoSisaE1E5bIndexForSV()
      : CommandBase(CmdName)
    {}

    SetGalileoSisaE1E5bIndexForSV::SetGalileoSisaE1E5bIndexForSV(int svId, int sisai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setSisai(sisai);
      setDataSetName(dataSetName);
    }

    SetGalileoSisaE1E5bIndexForSVPtr SetGalileoSisaE1E5bIndexForSV::create(int svId, int sisai, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoSisaE1E5bIndexForSV>(svId, sisai, dataSetName);
    }

    SetGalileoSisaE1E5bIndexForSVPtr SetGalileoSisaE1E5bIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoSisaE1E5bIndexForSV>(ptr);
    }

    bool SetGalileoSisaE1E5bIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Sisai"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoSisaE1E5bIndexForSV::documentation() const { return Documentation; }


    int SetGalileoSisaE1E5bIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetGalileoSisaE1E5bIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGalileoSisaE1E5bIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoSisaE1E5bIndexForSV::sisai() const
    {
      return parse_json<int>::parse(m_values["Sisai"]);
    }

    void SetGalileoSisaE1E5bIndexForSV::setSisai(int sisai)
    {
      m_values.AddMember("Sisai", parse_json<int>::format(sisai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGalileoSisaE1E5bIndexForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoSisaE1E5bIndexForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
