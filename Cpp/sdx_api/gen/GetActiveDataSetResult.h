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
    /// Result of GetActiveDataSet.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetName string The name of the data set to set as active.
    ///

    class GetActiveDataSetResult;
    typedef std::shared_ptr<GetActiveDataSetResult> GetActiveDataSetResultPtr;
    
    
    class GetActiveDataSetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetActiveDataSetResult();

      GetActiveDataSetResult(const std::string& system, const std::string& dataSetName);

      GetActiveDataSetResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName);

      static GetActiveDataSetResultPtr create(const std::string& system, const std::string& dataSetName);

      static GetActiveDataSetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName);
      static GetActiveDataSetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetActiveDataSetResult);
  }
}

