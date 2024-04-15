#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConstellationParameterForEachSV.
    ///
    /// Name        Type                                    Description
    /// ----------- --------------------------------------- ----------------------------------------------------------------------------------------------------
    /// System      string                                  "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
    /// ParamName   string                                  Refer to SetConstellationParameterForSV for accepted names.
    /// Val         array double or array int or array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc.).
    /// DataSetName optional string                         Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetConstellationParameterForEachSVResult;
    typedef std::shared_ptr<GetConstellationParameterForEachSVResult> GetConstellationParameterForEachSVResultPtr;
    
    
    class GetConstellationParameterForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConstellationParameterForEachSVResult();

      GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForEachSVResult(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      GetConstellationParameterForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForEachSVResultPtr create(const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForEachSVResultPtr create(const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<int>& val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForEachSVResultPtr create(const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetConstellationParameterForEachSVResult);
  }
}

