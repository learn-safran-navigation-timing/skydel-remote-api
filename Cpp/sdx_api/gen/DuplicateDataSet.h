#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Duplicate an existing data set.
    ///
    /// Name           Type            Description
    /// -------------- --------------- ----------------------------------------------------------------------------------
    /// System         string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetName    string          The name of the data set to duplicate.
    /// NewDataSetName optional string The name of the new duplicate data set. If omitted, a copy name will be generated.
    ///

    class DuplicateDataSet;
    typedef std::shared_ptr<DuplicateDataSet> DuplicateDataSetPtr;
    
    
    class DuplicateDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      DuplicateDataSet();

      DuplicateDataSet(const std::string& system, const std::string& dataSetName, const Sdx::optional<std::string>& newDataSetName = {});

      static DuplicateDataSetPtr create(const std::string& system, const std::string& dataSetName, const Sdx::optional<std::string>& newDataSetName = {});
      static DuplicateDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);


      // **** newDataSetName ****
      Sdx::optional<std::string> newDataSetName() const;
      void setNewDataSetName(const Sdx::optional<std::string>& newDataSetName);
    };
    
  }
}

