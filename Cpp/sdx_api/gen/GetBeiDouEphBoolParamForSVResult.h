#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouEphBoolParamForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// Val         bool            Parameter value (see table above for unit)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouEphBoolParamForSVResult;
    typedef std::shared_ptr<GetBeiDouEphBoolParamForSVResult> GetBeiDouEphBoolParamForSVResultPtr;
    
    
    class GetBeiDouEphBoolParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetBeiDouEphBoolParamForSVResult();

      GetBeiDouEphBoolParamForSVResult(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      GetBeiDouEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      static GetBeiDouEphBoolParamForSVResultPtr create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      static GetBeiDouEphBoolParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});
      static GetBeiDouEphBoolParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      bool val() const;
      void setVal(bool val);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouEphBoolParamForSVResult);
  }
}

