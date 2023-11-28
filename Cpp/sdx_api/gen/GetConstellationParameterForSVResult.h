#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConstellationParameterForSV.
    ///
    /// Name        Type                  Description
    /// ----------- --------------------- -------------------------------------------------------------------------------------------
    /// System      string                "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC".
    /// SvId        int                   The Satellite SV ID, or use 0 to apply new value to all satellites.
    /// ParamName   string                Parameter name (see table above for accepted names).
    /// Val         double or int or bool Parameter value (see table above for unit and type).
    /// DataSetName optional string       Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetConstellationParameterForSVResult;
    typedef std::shared_ptr<GetConstellationParameterForSVResult> GetConstellationParameterForSVResultPtr;
    
    
    class GetConstellationParameterForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetConstellationParameterForSVResult();

      GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      template<typename Type>
      Type val() const;
      template<typename Type>
      void setVal(Type val);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetConstellationParameterForSVResult);
  }
}

