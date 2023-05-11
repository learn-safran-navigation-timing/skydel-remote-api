#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set active data set.
    ///
    /// Name        Type   Description
    /// ----------- ------ ---------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "NavIC" or "QZSS"
    /// DataSetName string The name of the data set to set as active.
    ///

    class SetActiveDataSet;
    typedef std::shared_ptr<SetActiveDataSet> SetActiveDataSetPtr;
    
    
    class SetActiveDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetActiveDataSet();

      SetActiveDataSet(const std::string& system, const std::string& dataSetName);

      static SetActiveDataSetPtr create(const std::string& system, const std::string& dataSetName);
      static SetActiveDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      std::string dataSetName() const;
      void setDataSetName(const std::string& dataSetName);
    };
    
  }
}

