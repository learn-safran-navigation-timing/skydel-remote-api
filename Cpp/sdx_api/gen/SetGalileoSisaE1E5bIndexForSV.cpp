
#include "SetGalileoSisaE1E5bIndexForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoSisaE1E5bIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoSisaE1E5bIndexForSV::CmdName = "SetGalileoSisaE1E5bIndexForSV";
    const char* const SetGalileoSisaE1E5bIndexForSV::Documentation = "Set the SISA(E1,E5b) index of a Galileo satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Sisai       int             SISA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGalileoSisaE1E5bIndexForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoSisaE1E5bIndexForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoSisaE1E5bIndexForSV);


    SetGalileoSisaE1E5bIndexForSV::SetGalileoSisaE1E5bIndexForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoSisaE1E5bIndexForSV::SetGalileoSisaE1E5bIndexForSV(int svId, int sisai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetGalileoSisaE1E5bIndexForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Sisai", "DataSetName"}; 
      return names; 
    }


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
