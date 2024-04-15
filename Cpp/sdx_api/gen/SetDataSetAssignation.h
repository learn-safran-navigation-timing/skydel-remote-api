#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set data set assignation for the specified constellation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    /// DataSetName string The name of the assigned data set.
    ///

    class SetDataSetAssignation;
    typedef std::shared_ptr<SetDataSetAssignation> SetDataSetAssignationPtr;
    
    
    class SetDataSetAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDataSetAssignation();

      SetDataSetAssignation(const std::string& system, const std::string& dataSetType, const std::string& dataSetName);

      static SetDataSetAssignationPtr create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName);
      static SetDataSetAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

