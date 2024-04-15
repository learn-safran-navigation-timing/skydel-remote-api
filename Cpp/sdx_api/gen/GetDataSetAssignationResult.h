#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDataSetAssignation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    /// DataSetName string The name of the assigned data set.
    ///

    class GetDataSetAssignationResult;
    typedef std::shared_ptr<GetDataSetAssignationResult> GetDataSetAssignationResultPtr;
    
    
    class GetDataSetAssignationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDataSetAssignationResult();

      GetDataSetAssignationResult(const std::string& system, const std::string& dataSetType, const std::string& dataSetName);

      GetDataSetAssignationResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName);

      static GetDataSetAssignationResultPtr create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName);

      static GetDataSetAssignationResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName);
      static GetDataSetAssignationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetType ****
      std::string dataSetType() const;
      void setDataSetType(const std::string& dataSetType);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetDataSetAssignationResult);
  }
}

